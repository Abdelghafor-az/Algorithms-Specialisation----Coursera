// vertical linked list, replace two vertices by one

#include <stdio.h>
#include <stdlib.h>


typedef struct Edge {
    int y;
    struct Edge *next;
}
Edge;

typedef struct Vertex
{
    int x;
    struct Vertex *Adj;
    struct Edge *next;
}
Vertex;

Vertex *head = NULL;
int d = 0;

void Built_graph(void);
Vertex *Built_vertex(int v);
void Built_edge(Vertex *v, Vertex *w);
void Contraction(Vertex *v, Vertex *w);
void substitute(Vertex *v, Vertex *w);

int main(void)
{
    Built_graph();
    Vertex *v1, *v2, *v3;
    v1 = head; v2 = head->Adj; v3 = head->Adj->Adj;
    Contraction(v1, v2);
}

void Contraction(Vertex *v, Vertex *w)
{
    substitute(v, w);
    // 3lach mandkhelch delete f substitue aslan;
    // Delete(v1, v2);
    // Add(v1, v2);
    // Add();
}

void Built_graph(void)
{
    Vertex *v1 = Built_vertex(1);
    Vertex *v2 = Built_vertex(2);
    Vertex *v3 = Built_vertex(3);
    d = 4;

    // Vertex *vtxlist[] = {v1, v2, v3};
    // link_vlist(vtxlist)
    head = v1;
    v1->Adj = v2;
    v2->Adj = v3;

    Built_edge(v1, v2);
    Built_edge(v1, v3);
    Built_edge(v2, v1);
}

Vertex *Built_vertex(int v)
{
    Vertex *vertex = malloc(sizeof(Vertex));
    if (vertex != NULL)
    {
        vertex->x = v;
        vertex->Adj = NULL;
        vertex->next = NULL;
    }
    return vertex;
}

void Built_edge(Vertex *v, Vertex *w)
{
    Edge *e1 = malloc(sizeof(Edge));
    Edge *e2 = malloc(sizeof(Edge));
    if (e1 != NULL && e2 != NULL)
    {
        e1->y = v->x;
        e2->y = w->x;
        e1->next = w->next;
        e2->next = v->next;
    }
    w->next = e1;
    v->next = e2;
}

void Delete(Vertex *v)
{
    // free the v and w linked list of edges including the head and link the gaps
    Edge *ehead = v->next;
    Edge *tmp;
    while (ehead != NULL)
    {
       tmp = ehead;
       ehead = ehead->next;
       free(tmp);
    }

    int i = 1;
    printf("v: %p\n", v);
    for (Vertex *tmp1 = head; tmp1 != NULL; tmp1 = tmp1->Adj)
    {
        printf("i: %i | current: %p holds %i\n", i++, tmp1, tmp1->x); // 4 - 1 - 2 - 3
        // if (tmp1->x == 4)
        //     printf("the new vertex have two links with vertex %i vertex %i\n",
        //             tmp1->next->y, tmp1->next->next->y);
        if (tmp1->Adj == v)
        {
            // funct or just handle stuff on my own
            tmp1->Adj = tmp1->Adj->Adj;
            free(v);
        }
    }
}

void substitute(Vertex *v, Vertex *w)
{
    Vertex *vertex = malloc(sizeof(Vertex));
    if (v != NULL)
    {
        vertex->x = d++;
        vertex->Adj = head;
        vertex->next = NULL;
    }
    // fill the new_vertex linked list
    int a = vertex->x; int b = vertex->x;
    for (Vertex *tmp = head; tmp != NULL; tmp = tmp->Adj)
    {
        // if a and b finded, substitue with the new digit
        if (tmp == v || tmp == w)
            continue;
        for (Edge *edge = tmp->next; edge != NULL; edge = edge->next)
        {
            if (edge->y == a || edge->y == b)
            {
                edge->y = vertex->x;
                // create an edge for the new vertex and add at the beginning
                Edge *nedge = malloc(sizeof(Edge));
                nedge->y = tmp->x;
                nedge->next = vertex->next;
                vertex->next = nedge;
            }
        }
    }
    // finaly add the new created vertex at the beginniiing
    head = vertex;

    Delete(v);
    Delete(w);
}