/*      BFS: Breadth First Search
    a graph search algorithm - traversal aproach that explore the graph by layers, in other words
    we first walk through all nodes on the same level before moving on to the next level.
        by using a queue data structures
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
}
node;

node *front = NULL;
node *rear = NULL;

typedef struct Graph
{
    int vertices;
    struct node **AdjList;
    int *visited;
}
Graph;


// Queue prototype functions
int dequeue(void);
void enqueue(int);
int is_empty(void);
void print_queue(void);

// BFS prototype functions
void add_edge(Graph*,int,int);
void BFS(Graph*,int);
Graph *create_graph(int);
int strongly_connected(Graph *graph);

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
    
    int sc = strongly_connected(graph);
    printf("How many strongly connected nodes %d\n", sc);

    return 0;
}

int strongly_connected(Graph *graph)
{
    int strongly_connected_var = 0;
    node *temp = NULL;
    for (int i = 0; i < graph->vertices; i++)
    {
        temp = graph->AdjList[i];
        if (graph->visited[i] == 0)
        {
            BFS(graph, i);
            strongly_connected_var++;
        }
    }
    return strongly_connected_var;
}

void BFS(Graph *graph, int start_vertex)
{
    graph->visited[start_vertex] = 1;
    enqueue(start_vertex);

    while (!is_empty()) {
    int current_vertex = dequeue();

    node* temp = graph->AdjList[current_vertex];
    while (temp)
    {
        int adj_vertex = temp->number;

        if (graph->visited[adj_vertex] == 0)
        {
            graph->visited[adj_vertex] = 1;
            enqueue(adj_vertex);
        }
        temp = temp->next;
    }
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

void enqueue(int a)
{
    node *temp = malloc(sizeof(node));
    if (temp == NULL)
        return;
    temp->number = a;
    temp->next = NULL;

    // if It's the first node added, front also should point to it
    if (front == NULL && rear == NULL)
    {
        front = rear = temp;
        return;
    }
    rear->next = temp;
    rear = temp;
}

int dequeue(void)
{
    if (front == NULL)
        printf("the queue is empty\n");
    node *temp = front;
    int a = front->number;
    if (front == NULL)
        return -1;
    if (front == rear)
        front = rear = NULL;
    else
        front = front->next;
    free(temp);
    return a;
}

int is_empty(void)
{
    if (rear == NULL)
        return 1;
    return 0;
}

void print_queue(void)
{
    printf("[ ");
    for (node *temp = front; temp != NULL; temp = temp->next)
        printf("%d ", temp->number);
    printf("]");
}