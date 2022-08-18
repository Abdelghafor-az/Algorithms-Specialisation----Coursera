/*
    BFS (breath-first-search) : shortest path
*/

#include <stdio.h>
#include <stdlib.h>
// #include <stdbool.h> returning 0 or 1 instead of false and true

typedef struct node
{
    int number;
    struct node *next;
}
node;

struct node *front = NULL;
struct node *rear = NULL;
int CurrentLabel;

typedef struct Graph {
  int vertices;
  struct node** adjLists;
  int* visited;
}
Graph;

// Undirected Connectivity Components
int UCC(Graph* graph);

// Graph functions
void BFS(Graph* graph, int startVertex);
Graph* createGraph(int vertices);
void addEdge(Graph* graph, int src, int dest);

// Queue functions
void Enqueue(int x);
int Dequeue(void);
int isEmpty(void);
void Printq(void);

int main(void)
{
    Graph *graph = createGraph(10);

    addEdge(graph, 0, 2);
    addEdge(graph, 0, 4);
    addEdge(graph, 2, 4);
    addEdge(graph, 4, 6);
    addEdge(graph, 4, 8);
    addEdge(graph, 1, 3);
    addEdge(graph, 5, 7);
    addEdge(graph, 5, 9);
    addEdge(graph, 7, 9);

    int ucc = UCC(graph);
    printf("there is %i unconnected components\n", ucc); // 3

    return 0;
}

int UCC(Graph* graph)
{
    // start from the first vertex, donsen't matter wich one
    int ucc = 0;
    for (int i = 0; i < graph->vertices; i++)
    {
        // node *tmp = graph->adjLists[i];
        if (graph->visited[i] == 0)
        {
            ucc++;
            BFS(graph, i);
        }
    }
    return ucc;
}

// BFS Algorithm
void BFS(Graph* graph, int startVertex)
{
    // struct queue* q = createQueue();
    graph->visited[startVertex] = 1;
    Enqueue(startVertex);

    while (!isEmpty()) {
    int currentVertex = Dequeue();

    node* temp = graph->adjLists[currentVertex];
    while (temp)
    {
        int adjVertex = temp->number;

        if (graph->visited[adjVertex] == 0)
        {
            graph->visited[adjVertex] = 1;
            Enqueue(adjVertex);
        }
        temp = temp->next;
    }
    }
}

Graph *createGraph(int vertices) {
  Graph* graph = malloc(sizeof(Graph));
  graph->vertices = vertices;
  CurrentLabel = vertices;

  graph->adjLists = malloc(vertices * sizeof(node));
  graph->visited = calloc(vertices, sizeof(int));

  int i;
  for (i = 0; i < vertices; i++) {
    graph->adjLists[i] = NULL;
    // graph->visited[i] = 0; // because we are using calloc, we don't need this initialisation
  }

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
