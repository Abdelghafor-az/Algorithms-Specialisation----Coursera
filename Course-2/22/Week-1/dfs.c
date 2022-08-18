/*      DFS: Deep First Search
    a graph search algorithm - traversal approach in which the traverse begins
    at the root node and proceeds through the nodes as far as possible until we reach
    the node with no unvisited nearby nodes.
    based on the recursive calls
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
}
node;

typedef struct Graph
{
    int vertices;
    struct node **AdjList;
    int *visited;
}
Graph;

// DFS prototype functions
void DFS(Graph*,int);
Graph *create_graph(int);
void add_edge(Graph*,int,int);

int main(void)
{
    int vertices = 6;
    Graph *graph = create_graph(vertices);

    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 2, 3);
    add_edge(graph, 2, 4);
    add_edge(graph, 3, 4);
    add_edge(graph, 3, 5);
    add_edge(graph, 4, 5);

    // for (int i = 0; i < vertices; i++)
    //     printf("%p ", graph->AdjList[i]);
    DFS(graph, 0);

    for (int i = 0; i < vertices; i++)
        printf("%d ", graph->visited[i]);

    return 0;
}

void DFS(Graph *graph, int start_vertex)
{
    graph->visited[start_vertex] = 1;
    node* temp = graph->AdjList[start_vertex];
    
    while (temp)
    {
        int adj_vertex = temp->number;
        if (graph->visited[adj_vertex] == 0)
        {
            graph->visited[adj_vertex] = 1;
            DFS(graph, adj_vertex);
        }
        temp = temp->next;
    }
}

Graph *create_graph(int vertices)
{
    Graph *graph = malloc(sizeof(Graph));
    graph->AdjList = malloc(vertices * sizeof(node));
    graph->visited = calloc(vertices, sizeof(int));
    graph->vertices = vertices;

    for (int i = 0; i < vertices; i++)
        graph->AdjList[i] = NULL;
    // printf("%d\n", sizeof(graph->AdjList[0]));

    return graph;
}

void add_edge(Graph *graph, int src, int dest)
{
    // undirected Graph, edge from src->dest and the opposite

    // Add edge from src to dest
    node* n = malloc(sizeof(node));
    if (n == NULL)
        return;
    n->number = dest;
    n->next = graph->AdjList[src];
    graph->AdjList[src] = n;

    // Add edge from dest to src
    n = malloc(sizeof(node));
    if (n == NULL)
        return;
    n->number = src;
    n->next = graph->AdjList[dest];
    graph->AdjList[dest] = n;
}