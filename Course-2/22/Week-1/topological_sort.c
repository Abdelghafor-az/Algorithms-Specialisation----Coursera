/*                      Topological Sort
    application of DFS on directed graph algorithm that used to sort
    the vertices in order to have each vertex pointing to the front,
    and no one pointing backward --  So the order should the same!
    whatever the vertex you start with! the parent node is the parent
    node (labeled 1), and the slick is the slick (labeled n)
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    // int topological_order; ? or an array in the graph is better?
    // Actualy, It should be an array, becoz (because) that's the simplest
    // way to print the topological order in the main function
    struct node *next;
}
node;

typedef struct Graph
{
    int vertices;
    struct node **AdjList;
    int *visited;
    int *topological_order;
    int current_label;
}
Graph;

// DFS prototype functions
void add_edge(Graph*,int,int);
Graph *create_graph(int);
void DFS(Graph*,int);
void topological_sort(Graph*,int);

int main(void)
{
    int vertices = 4;
    Graph *graph = create_graph(vertices);

    add_edge(graph, 1, 0);
    add_edge(graph, 0, 2);
    add_edge(graph, 3, 1);
    add_edge(graph, 3, 2);

    topological_sort(graph, 1);

    for (int i = 0; i < vertices; i++)
        printf("%d ", graph->topological_order[i]);

    return 0;
}

void topological_sort(Graph *graph, int vertex)
{
    // int current_label = graph->vertices;
    DFS(graph, vertex);
    for (int i = 0; i < graph->vertices; i++)
    {
        if (graph->visited[i] == 0)
            DFS(graph, i);
    }
}

void DFS(Graph *graph, int start_vertex)
{
    graph->visited[start_vertex] = 1;
    node* temp = graph->AdjList[start_vertex];
    int order = 0;

    while (temp)
    {
        int adj_vertex = temp->number;
        if (graph->visited[adj_vertex] == 0)
        {
            DFS(graph, adj_vertex);
        }
        temp = temp->next;
    }
    order = graph->current_label; // for Debugging
    graph->topological_order[start_vertex] = graph->current_label--;
}

Graph *create_graph(int vertices)
{
    Graph *graph = malloc(sizeof(Graph));
    graph->AdjList = malloc(vertices * sizeof(node));
    graph->visited = calloc(vertices, sizeof(int));
    graph->topological_order = calloc(vertices, sizeof(int));
    graph->vertices = vertices;
    graph->current_label = vertices;

    for (int i = 0; i < vertices; i++)
        graph->AdjList[i] = NULL;
    // printf("%d\n", sizeof(graph->AdjList[0])); => 8

    return graph;
}

void add_edge(Graph *graph, int src, int dest)
{
    // directed Graph, just an edge from src->dest

    // Add edge from src to dest
    node* n = malloc(sizeof(node));
    if (n == NULL)
        return;
    n->number = dest;
    n->next = graph->AdjList[src];
    graph->AdjList[src] = n;

    // Add edge from dest to src
    // n = malloc(sizeof(node));
    // if (n == NULL)
    //     return;
    // n->number = src;
    // n->next = graph->AdjList[dest];
    // graph->AdjList[dest] = n;
}