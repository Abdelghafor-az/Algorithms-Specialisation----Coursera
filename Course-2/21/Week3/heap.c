// Implementaion Of Heap with d-array (I don't know what d mean yet !)

#include <stdio.h>
#include <stdlib.h>


// Heap prototype functions
void intialize_Array(int []);
void insert(int [],int);
int extract_min(int []);
void print_heap(int Heap[]);

int main(void)
{
    const int ARRAY_SIZE = 10;
    int Heap[ARRAY_SIZE];
    Heap[0] = ARRAY_SIZE;
    intialize_Array(Heap);
    // Operation: insert - extract_Min - Heapify (n batched inserts in O(n))
    // delete(maybe) - heap_Balance?? - increase_Heap_Size
    // next task is speed dijkstra's algorithm by implementing with heap
    // 3-4-8-9-4-12-9-11-13
    // parent(i) = [i/2 i even or odd]
    // child(i) = [2i, 2i+1]
    // Yes, Alhamdulilah, I'll save the lenght in Heap[0]
    // and k last index in Heap[Heap[0]-1]
    insert(Heap, 3);
    insert(Heap, 4);
    insert(Heap, 8);
    insert(Heap, 9);
    insert(Heap, 4);
    insert(Heap, 2);

    print_heap(Heap);

    printf("min = %d\n", extract_min(Heap));
    printf("#################\n");

    print_heap(Heap);

    return 0;
}

void intialize_Array(int Heap[])
{
    for (int i = 1; i < Heap[0]-1; i++)
        Heap[i] = INT_MAX;
    // let the last element free to store k the last index
    Heap[Heap[0]-1] = 1;
}

void insert(int Heap[], int data)
{
    int last_index = Heap[0] - 1; // I'm storing the lenght in Heap[0]
    int k = Heap[last_index];
    Heap[last_index]++;
    if (Heap[0] == Heap[k]+1) // Heap[0]==10 and Heap[k] is 9 so Heap[9] is the last element
    {
        // int l = increase_Heap_Size(Heap);
        // Heap[0] = l; Heap[l-1] = Heap[last_index];
        // Heap[k] = INT_MAX; // I have to free It
    }
    // if things are safe, go!
    if (Heap[k] != INT_MAX)
        printf("Eror !!!, Heap[%d] = %d is not free.", k, Heap[k]);
    Heap[k] = data;
    if (k == 1)
        return; // enough, there no parent to bubble up.

    // Now, bubble up if needed
    int tmp;
    while (Heap[k] < Heap[k / 2] && k != 1) // k != 1 so it dosen't change Heap[0] content
    {
        // swap
        tmp = Heap[k / 2];
        Heap[k / 2] = Heap[k];
        Heap[k] = tmp;
        // update k to check again
        k = k / 2;
    }
}

int extract_min(int Heap[])
{
    int last_index = Heap[0] - 1;
    int min = Heap[1];
    Heap[1] = Heap[Heap[last_index] - 1];
    printf("***%d\n", Heap[1]);
    Heap[Heap[last_index] - 1] = INT_MAX;
    Heap[last_index]--;
    // Bubble down
    int i = 1, tmp;
    int s = Heap[2] < Heap[3] ? 2 : 3;
    printf("s is %d\n", s);
    while (Heap[i] > Heap[s])
    {
        // swap
        // printf("Yes I get In\n");
        tmp = Heap[i];
        Heap[i] = Heap[s];
        Heap[s] = tmp;
        // update variables to check again
        i = s;
        s = Heap[2 * i] < Heap[2 * i + 1] ? 2 * i : 2 * i + 1;
    }

    return min;
}

void print_heap(int Heap[])
{
    for (int i = 0; i < Heap[0]; i++)
        printf("%d\n", Heap[i]);
}
