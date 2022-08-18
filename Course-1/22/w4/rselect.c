/*                  Randomized Selection
        a Linear Randomized Algorithm for Selection
                run on averrage in O(n)

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int[],int,int);
void print_arr(int[],int);
int rselect(int[],int,int,int);
int  rand_pivot(int[],int,int);
void swap(int[],int,int);

int main(void)
{
    int A[] = {3,0,-73,11,8,-2,5,89,4,7,6};
    int len = sizeof(A) / sizeof(int);

    print_arr(A, len);

    // Quick Sort
    int ith = 4;
    int ith_smallest = rselect(A, 0, len-1, ith-1);

    print_arr(A, len);
    printf("the %dth smallest element is %d\n", ith, ith_smallest);

    return 0;
}

int rselect(int A[], int start, int end, int ith)
{
    if (start < end)
    {
        int index = partition(A, start, end);
        printf("%i\n", index);
        /* if the chosen pivot is the ith smallest element
        return A[ith=6], if ith < index=4 recurse on the left,
        so rselect(start,index-1,ith)
        else (ith > index) we must modiy the ith
        => rselect(index+1=5,end=10,number=ith-index)
        */
        if (index == ith)
            return A[ith];
        else if (ith < index)
            return rselect(A, start, index-1, ith);
        else
            return rselect(A, index+1, end, ith-index);
    }
}

int partition(int A[], int start, int end)
{
    // Choose rand pivot - swap with start to be easy
    int p = rand_pivot(A, start, end);
    int pivot = A[p];
    swap(A, start, p);
    // Start the partition around the pivot
    int i = start + 1, temp;
    for (int k = start+1; k <= end; k++)
    {
        if (A[k] < pivot)
            swap(A, k, i++);
    }
    swap(A, start, i-1);

    return i-1;
}

int rand_pivot(int A[], int start, int end)
{
    // Choose random pivot
    srand(time(NULL));
    int p = rand() % (end - start + 1) + start;
    return p;
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
