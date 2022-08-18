#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int number;
    struct node *next;
}
node;

typedef struct Graph {
  int vertices;
  struct node** adjLists;
  int* visited;
}
Graph;

// Graph functions
void DFS(struct Graph* graph, int vertex);
Graph* createGraph(int vertices);
void addEdge(Graph* graph, int src, int dest);

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
    addEdge(graph, 4, 5);

    DFS(graph, 0);

    for (int i = 0; i < graph->vertices; i++)
    {
        printf("%i ", graph->visited[i]);
    }
    printf("\n");

    return 0;
}

// DFS Algorithm
void DFS(struct Graph* graph, int vertex)
{
    graph->visited[vertex] = 1;

    node* temp = graph->adjLists[vertex];
    while (temp)
    {
        int nextVertex = temp->number;
        if (graph->visited[nextVertex] == 0)
            DFS(graph, nextVertex);
        
        temp = temp->next;
    }
}

Graph *createGraph(int vertices)
{
    Graph* graph = malloc(sizeof(Graph));
    graph->vertices = vertices;

    graph->adjLists = malloc(vertices * sizeof(node));
    graph->visited = calloc(vertices, sizeof(int));

    for (int i = 0; i < vertices; i++)
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
    // n = malloc(sizeof(node));
    // if (n == NULL)
    //     return;
    // n->number = src;
    // n->next = graph->adjLists[dest];
    // graph->adjLists[dest] = n;
}
