#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    int order;
    struct node *next;
}
node;

typedef struct Graph
{
    int vertices;
    int *visited;
    int *order;
    node **adjLists;
}
Graph;


// Graph functions
void DFS_loop(Graph *graph);
void DFS(Graph *graph, int vertex);
Graph *createGraph(int v);
void addEdge(Graph *graph, int src, int dest);

int current_label;

int main(void)
{
    Graph *graph = createGraph(4);

    addEdge(graph, 1, 0);
    addEdge(graph, 0, 2);
    addEdge(graph, 3, 1);
    addEdge(graph, 3, 2);

    DFS_loop(graph);

    for (int i = 0; i < graph->vertices; i++)
        printf("%i ", graph->visited[i]);
    printf("\n");

    for (int i = 0; i < graph->vertices; i++)
        printf("%i:%i ", i, graph->order[i]);
    printf("\n");

    return 0;
}

// topological sort
void DFS_loop(Graph *graph)
{
    DFS(graph, 1);
    for (int i = 0; i < graph->vertices; i++)
    {
        if (graph->visited[i] == 0)
            DFS(graph, i);
    }
}

// DFS Algorithm
void DFS(Graph *graph, int vertex)
{
    // printf("%i\n", vertex);
    graph->visited[vertex] = 1;
    node *temp = graph->adjLists[vertex];
    while (temp)
    {
        int nextVertex = temp->number;
        if (graph->visited[nextVertex] == 0)
            DFS(graph, nextVertex);
        temp = temp->next;
    }
    graph->order[vertex] = current_label;
    current_label--;
}


Graph *createGraph(int v)
{
    Graph *graph = malloc(sizeof(Graph));
    if (graph)
    {
        current_label = v;
        graph->vertices = v;
        graph->order = calloc(v, sizeof(int));
        graph->visited = calloc(v, sizeof(int));
        graph->adjLists = malloc(v * sizeof(int*));
    }

    for (int i = 0; i < v; i++)
        graph->adjLists[i] = NULL;

    return graph;
}

void addEdge(Graph *graph, int src, int dest)
{
    node *n = malloc(sizeof(node));
    if (!n) return;
    n->number = dest;
    n->order = 0;
    n->next = graph->adjLists[src];
    graph->adjLists[src] = n;
    /////////////////////////
    // n = malloc(sizeof(node));
    // if (!n) return;
    // n->number = src;
    // n->next = graph->adjLists[dest];
    // graph->adjLists[dest] = n;
}