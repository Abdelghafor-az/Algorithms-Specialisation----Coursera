#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
} node;

typedef struct Graph
{
    int vertices;
    int *visited;
    node **adjLists;
} Graph;

Graph *createGraph(int v);
void addEdge(Graph *graph, int src, int dest);
void addLastEdge(Graph *graph, int src, int dest);
Graph *reverseGraph(Graph *graph);

int T = 0;

int main(void)
{
    Graph *graph = createGraph(4);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);

    for (int i = 0; i < graph->vertices; i++)
    {
        printf("The vertex %i is linked to [", i);
        node *tmp = graph->adjLists[i];
        while (tmp)
        {
            printf(":%i:", tmp->number);
            tmp = tmp->next;
        }
        printf("]\n");
    }

    Graph *rvgraph = reverseGraph(graph);
    // return 0;

    for (int j = 0; j < rvgraph->vertices; j++)
    {
        printf("The vertex %i is linked to [", j);
        node *tmp = rvgraph->adjLists[j];
        while (tmp)
        {
            printf(":%i:", tmp->number);
            tmp = tmp->next;
        }
        printf("]\n");
    }

    // return 0;
}

Graph *createGraph(int v)
{
    Graph *graph = malloc(sizeof(Graph));
    if (graph)
    {
        graph->vertices = v;
        graph->visited = calloc(v, sizeof(int));
        graph->adjLists = malloc(v * sizeof(int *));
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
    for (int i = 0; i < graph->vertices; i++)
    {
        node *tmp = graph->adjLists[i];
        while (tmp)
        {
            int nextVertex = tmp->number;
            node *catch = tmp;
            addEdge(rev_graph, nextVertex, i);
            tmp = tmp->next;
        }
    }
    return rev_graph;
}