/*
    Dijkstra's Algorithm : shortest path algorithm for weighted graphs
*/

#include <stdio.h>
#include <stdlib.h>
// #include <stdbool.h>
// X - returning 0 or 1 instead of false and true

typedef struct node
{
    int number;
    int distance;
    struct node *next;
}
node;

typedef struct Graph {
  int vertices;
  struct node** adjLists;
  int* sp;
}
Graph;

// Graph prototype functions
void Dijkstra(struct Graph* graph, int startVertex);
Graph* createGraph(int vertices);
void addEdge(Graph* graph, int src, int dest, int dist);
void printGraph(Graph *graph);

// Custom linked list
node *addNode(node *list, int data, int dist);
node *deleteMin(node *list, int *pn);
void printList(node *list);
int scanList(node *list, int m);
int isEmpty(node *list);

int main(void)
{
    int startVertex = 0;
    Graph *graph = createGraph(7);

    addEdge(graph, 0, 1, 2);
    addEdge(graph, 0, 3, 10);
    addEdge(graph, 1, 2, 3);
    addEdge(graph, 2, 3, 2);
    addEdge(graph, 2, 5, 1);
    addEdge(graph, 4, 0, 4);
    addEdge(graph, 4, 2, 5);
    addEdge(graph, 5, 4, 0);
    addEdge(graph, 5, 2, 9);
    addEdge(graph, 5, 3, 8);
    addEdge(graph, 6, 5, 7);

    // printGraph(graph);

    Dijkstra(graph, startVertex);

    // Print the results
    printf("The shortest path from Vertex %d to:\n", startVertex);
    for (int i = 0; i < graph->vertices; i++)
    {
        if (i == startVertex)
            continue;
        printf("%d: %i\n", i, graph->sp[i]);
    }
    printf("\n");
    
    return 0;
}

// Dijkstra's Algorithm
void Dijkstra(Graph *graph, int startVertex)
{
    node *list = NULL;
    // insert vertex
    list = addNode(list, startVertex, 0);
    graph->sp[startVertex] = 0;

    int counter = 0;
    while (list)
    {
        int n;
        list = deleteMin(list, &n);
        node *tmp = graph->adjLists[n];
        // printf("%d list: (d=%d)\n", n, graph->sp[n]);
        while (tmp) {
            // Relaxation
            int m = tmp->number, d = tmp->distance;
            int a = graph->sp[n], b = graph->sp[m];
            if (a + d < b)
            {
                graph->sp[m] = a+d;
                if (!scanList(list, m))
                    list = addNode(list, m, d);
            }
            tmp = tmp->next;
        }
        // printList(list);
        // printf("------------\n");
    }
    return;
}

Graph *createGraph(int vertices)
{
    Graph* graph = malloc(sizeof(Graph));
    graph->vertices = vertices;
    graph->adjLists = malloc(vertices * sizeof(node));
    graph->sp = calloc(vertices, sizeof(int));

    for (int i = 0; i < vertices; i++)
    {
        graph->adjLists[i] = NULL;
        graph->sp[i] = INT_MAX;
    }

    return graph;
}

void addEdge(Graph* graph, int src, int dest, int dist)
{
    // Add edge from src to dest
    node* n = malloc(sizeof(node));
    if (n == NULL)
        return;
    n->number = dest;
    n->distance = dist;
    n->next = graph->adjLists[src];
    graph->adjLists[src] = n;
}

node *addNode(node *list, int data, int dist)
{
    node *n = malloc(sizeof(node));
    if (!n)
        return NULL;
    n->number = data;
    n->distance = dist;
    n->next = list;
    list = n;
    return list;
}

node *Delete(node *list, int n)
{
    node *temp1 = list;
    if (n == 1)
    {
        list = list->next;
        free(temp1);
        return list;
    }
    for (int i = 0; i < n-2; i++)
        temp1 = temp1->next;
    node *temp2 = temp1->next;
    temp1->next = temp2->next;
    free(temp2);
    return list;
}

node *deleteMin(node *list, int *pn)
{
    // Find Min
    int min = __INT_MAX__;
    int counter = 1, position;
    node *tmp1 = list;
    if (!list)
       return NULL;
    
    while (tmp1)
    {
        if (tmp1->distance < min)
        {
            min = tmp1->number;
            position = counter;
        }
        tmp1 = tmp1->next;
        counter++;
    }
    // Delete It
    list = Delete(list, position);
    *pn = min;
    return list;
}

void printGraph(Graph *graph)
{
    printf("Let's print the graph\n");
    for (int i = 0; i < graph->vertices; i++)
    {
        node *tmp = graph->adjLists[i];
        printf("%d: ", i);
        while (tmp)
        {
            printf("%d\t", tmp->number);
            tmp = tmp->next;
        }
        printf("\n");
    }
}

void printList(node *list)
{
    printf("list printing ...\n");
    for (node *tmp = list; tmp != NULL; tmp = tmp->next)
        printf("%i\t", tmp->number);
    printf("\nEnd printing.\n");
}

int scanList(node *list, int m)
{
    for (node *tmp = list; tmp; tmp = tmp->next)
    {
        if (tmp->number == m)
        {
            return 1;
        }
    }
    return 0;
}

int isEmpty(node* list)
{
    if (list == NULL)
        return 1;
    return 0;
}

// I Learned that when never I passed a local pointer I should return It
// How easy it sounds, I suffered to beleive in It.