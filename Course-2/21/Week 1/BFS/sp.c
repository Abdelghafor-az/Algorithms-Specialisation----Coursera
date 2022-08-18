/*
    BFS (breath-first-search) : shortest path
*/

#include <stdio.h>
#include <stdlib.h>
// #include <stdbool.h> returning 0 or 1 instead of false and true

typedef struct node
{
    int dist;
    int number;
    struct node *next;
}
node;

struct node *front = NULL;
struct node *rear = NULL;

typedef struct Graph {
  int vertices;
  struct node** adjLists;
  int* visited;
}
Graph;

// Graph functions
int BFS_SP(Graph* graph, int startVertex, int destination);
Graph* createGraph(int vertices);
void addEdge(Graph* graph, int src, int dest);

// Queue functions
void Enqueue(int x);
int Dequeue(void);
int isEmpty(void);
void Printq(void);

int main(void)
{
    Graph *graph = createGraph(6);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);
    addEdge(graph, 3, 5);
    addEdge(graph, 3, 5);

    int sp = BFS_SP(graph, 0, 5);
    printf("%i\n", sp);

    // printf("\n");
    // for (int i = 0; i < graph->vertices; i++)
    // {
    //     printf("%i ", graph->visited[i]);
    // }
    // printf("\n");

    return 0;
}

// BFS Algorithm
int BFS_SP(Graph* graph, int startVertex, int destination)
{
    graph->visited[startVertex] = 1;
    graph->adjLists[startVertex]->dist = 0;
    Enqueue(startVertex);

    int prev = 0;
    while (!isEmpty()) {
        int currentVertex = Dequeue();
        int label = graph->adjLists[currentVertex]->dist;

        for (node* temp = graph->adjLists[currentVertex]; temp != NULL; temp = temp->next)
        {
            int adjVertex = temp->number;
            if (graph->visited[adjVertex] == 0)
            {
                graph->visited[adjVertex] = 1;
                graph->adjLists[adjVertex]->dist = label + 1;
                Enqueue(adjVertex);
            }
        }

    }
    int distance = graph->adjLists[destination]->dist;
    return distance;
}

Graph *createGraph(int vertices)
{
    Graph* graph = malloc(sizeof(Graph));
    graph->vertices = vertices;

    graph->adjLists = malloc(vertices * sizeof(node));
    graph->visited = calloc(vertices, sizeof(int));

    int i;
    for (i = 0; i < vertices; i++)
        graph->adjLists[i] = NULL;

    return graph;
}

void addEdge(Graph* graph, int src, int dest)
{
    // Add edge from src to dest
    node* n = malloc(sizeof(node));
    if (n == NULL)
        return;
    n->number = dest;
    n->next = graph->adjLists[src];
    graph->adjLists[src] = n;

    // Add edge from dest to src
    n = malloc(sizeof(node));
    if (n == NULL)
        return;
    n->number = src;
    n->next = graph->adjLists[dest];
    graph->adjLists[dest] = n;
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
        return -1; // false in while loop / while (!isEmpty)
    if (front == rear)
        front = rear = NULL;
    else
        front = front->next;

    free(tmp);
    return n;
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
        printf("%i\n", tmp->number);
    }

}