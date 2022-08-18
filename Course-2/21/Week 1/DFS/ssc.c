#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
} node;

struct node *front = NULL;
struct node *rear = NULL;

typedef struct Graph
{
    int vertices;
    int *visited;
    int *finishingTimes;
    int *leader;
    node **adjLists;
    node **sorted_adjLists;
} Graph;

// Queue functions
void Enqueue(int x);
int Dequeue(void);
int queue_length(void);
int isEmpty(void);
void Printq(void);

// Graph functions
void DFS_loop(Graph *graph);
void DFS_st(Graph *graph, int vertex);
void DFS_nd(Graph *graph, int vertex);
Graph *createGraph(int v);
void addEdge(Graph *graph, int src, int dest);
Graph *reverseGraph(Graph *graph);
void printSCC(Graph *graph);

int T = 0;

int main(void)
{
    Graph *graph = createGraph(9);

    // addEdge(graph, 1, 0);
    // addEdge(graph, 2, 1);
    // addEdge(graph, 0, 2);
    // addEdge(graph, 0, 3);
    // addEdge(graph, 3, 4);
    addEdge(graph, 0, 3);
    addEdge(graph, 3, 6);
    addEdge(graph, 6, 0);
    addEdge(graph, 8, 6);
    addEdge(graph, 8, 2);
    addEdge(graph, 2, 5);
    addEdge(graph, 5, 8);
    addEdge(graph, 7, 5);
    addEdge(graph, 7, 4);
    addEdge(graph, 4, 1);
    addEdge(graph, 1, 7);

    DFS_loop(graph);

    for (int i = 0; i < graph->vertices; i++)
        printf("%i ", graph->leader[i]);
    printf("\n");

    printSCC(graph);

    return 0;
}

// topological sort
void DFS_loop(Graph *graph)
{
    Graph *rev_graph = reverseGraph(graph);
    for (int i = rev_graph->vertices-1; i >= 0; i--)
    {
        if (rev_graph->visited[i] == 0)
            DFS_st(rev_graph, i);
    }

    // copy the finishingTimes array
    // from the reversedGraph to the actual Graph
    for (int j = 0; j < graph->vertices; j++)
    {
        graph->finishingTimes[j] = rev_graph->finishingTimes[j];
    }

    for (int f = 0; f < graph->vertices; f++)
    {
        node *tmp = graph->adjLists[f];
        graph->sorted_adjLists[graph->finishingTimes[f]] = tmp;
    }

    // second DFS
    for (int k = graph->vertices-1; k >= 0; k--)
    {
        if (graph->visited[k] == 0)
            DFS_nd(graph, k);
    }
}

void DFS_st(Graph *graph, int vertex)
{
    // DFS on Grev
    graph->visited[vertex] = 1;
    node *temp = graph->adjLists[vertex];

    while (temp)
    {
        int nextVertex = temp->number;
        // if (vertex == 5)
        // {
        //     printf("%i -  visited? %i\n", nextVertex, graph->visited[nextVertex]);
        // }
        if (graph->visited[nextVertex] == 0)
            DFS_st(graph, nextVertex);
        temp = temp->next;
    }
    graph->finishingTimes[vertex] = T++;
}

void DFS_nd(Graph *graph, int vertex)
{
    // printf("%i\n", vertex);
    graph->visited[vertex] = 1;
    node *temp = graph->sorted_adjLists[vertex];
    Enqueue(vertex);
    // Printq();

    while (temp)
    {
        int nextVertex = graph->finishingTimes[temp->number];
        if (graph->visited[nextVertex] == 0)
        {
            // printf("vertex%i will be called\n", nextVertex);
            DFS_nd(graph, nextVertex);
        }
        temp = temp->next;
    }

    int len = queue_length();
    while (len > 0)
    {
        int node = Dequeue();
        graph->leader[node] = vertex;
        len--;
    }
}

Graph *createGraph(int v)
{
    Graph *graph = malloc(sizeof(Graph));
    if (graph)
    {
        graph->vertices = v;
        graph->visited = calloc(v, sizeof(int));
        graph->leader = calloc(v, sizeof(int));
        graph->finishingTimes = calloc(v, sizeof(int));
        graph->adjLists = malloc(v * sizeof(int *));
        graph->sorted_adjLists = malloc(v * sizeof(int *));
    }

    for (int i = 0; i < v; i++)
        graph->adjLists[i] = NULL;

    return graph;
}

void addEdge(Graph *graph, int src, int dest)
{
    node *n = malloc(sizeof(node));
    if (!n)
        return;
    n->number = dest;
    n->next = graph->adjLists[src];
    graph->adjLists[src] = n;
}

Graph *reverseGraph(Graph *graph)
{
    Graph *rev_graph = createGraph(graph->vertices);
    // for (int i = 0; i < graph->vertices; i++)
    for (int i = graph->vertices-1; i >= 0; i--)
    {
        node *tmp = graph->adjLists[i];
        while (tmp)
        {
            int nextVertex = tmp->number;
            addEdge(rev_graph, nextVertex, i);
            tmp = tmp->next;
        }
        
    }
    return rev_graph;
}

void printSCC(Graph *graph)
{
    int *printed = calloc(graph->vertices, sizeof(int));
    printf("Strong Connected Components\n");
    for (int i = 0; i < graph->vertices; i++)
    {
        int label = graph->leader[i];
        if (printed[i] == 1)
            continue;
        for (int j = 0; j < graph->vertices; j++)
        {
            if (label == graph->leader[j])
            {
                printf("%i ", j+1);
                printed[j] = 1;
            }
        }
        printf("\n");
    }

}

void Enqueue(int x)
{
    node *tmp = malloc(sizeof(node));
    if (tmp != NULL)
    {
        tmp->number = x;
        tmp->next = NULL;
    }

    if (front == NULL && rear == NULL)
    {
        front = rear = tmp;
        return;
    }
    rear->next = tmp;
    rear = tmp;
}

int Dequeue(void)
{
    node *tmp = front;
    int n = front->number;
    if (front == NULL)
        return -1;
    if (front == rear)
        front = rear = NULL;
    else
        front = front->next;

    free(tmp);
    return n;
}

int queue_length(void)
{
    int counter = 0;
    node *tmp = front;
    while(tmp)
    {
        tmp = tmp->next;
        counter++;
    }
    return counter;
}

int isEmpty(void)
{
    if (rear == NULL)
        return 1;
    return 0;
}

void Printq(void)
{
    for (node *tmp = front; tmp != NULL; tmp = tmp->next)
    {
        printf("%i ", tmp->number);
    }
    printf("\n");
}