/*                  Quick Sort
    a Randomized Algorithm for Sorting, run on averrage in
    O(nlog(n)) to have this running time we need a 25-75 pivot
    all the important work happen is the partition, where
    we choose a pivot and
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int[],int,int);
void print_arr(int[],int);
void q_sort(int[],int,int);
int  rand_pivot(int[],int,int);
void swap(int[],int,int);

int main(void)
{
    int A[] = {3,0,11,8,2,5,89,1,4,7,6};
    int len = sizeof(A) / sizeof(int);

    print_arr(A, len);

    // Quick Sort
    q_sort(A, 0, len-1);

    print_arr(A, len);

    return 0;
}

void q_sort(int A[], int start, int end)
{
    if (start < end)
    {
        int index = partition(A, start, end);
        printf("%i\n", index);
        q_sort(A, start, index-1);
        q_sort(A, index+1, end);
    }
}

int partition(int A[], int start, int end)
{
    int i = start + 1, temp;
    int p = rand_pivot(A, start, end);
    int pivot = A[p];
    // swap with start to be easy
    // swap(A, start, p);
    temp = A[start];
    A[start] = A[p];
    A[p] = temp;
    for (int k = start+1; k <= end; k++)
    {
        if (A[k] < pivot)
            swap(A, k, i++);
    }
    swap(A, start, i-1);
    

    return i-1;
}

void swap(int A[], int x, int y)
{
    int temp;
    temp = A[x];
    A[x] = A[y];
    A[y] = temp;
    return;
}

void print_arr(int A[], int len)
{
    printf("[ ");
    for (int i = 0; i < len; i++)
    {
        printf("%d ", A[i]);
    }
    printf("]\n");
    
}

int rand_pivot(int A[], int start, int end)
{
    // Choose random pivot
    srand(time(NULL));
    int p = rand() % (end - start + 1) + start;
    return p;
}