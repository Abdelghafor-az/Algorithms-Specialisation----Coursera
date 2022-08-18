#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void q_sort(int A[], int start, int end);
int Partition(int A[], int start, int end);
int rand_pivot(int start, int end);

int main(void) {
    int A[] = {3, 8, 2, 5, 1, 4, 7, 6};
    int length = sizeof(A) / sizeof(A[0]);
    for (int i = 0; i < length; i++)
        printf("%i ", A[i]);
    printf("\n");

    q_sort(A, 0, length - 1);

    for (int i = 0; i < length; i++)
        printf("%i ", A[i]);
    printf("\n");
}

void q_sort(int A[], int start, int end)
{
    if (start < end)
    {
        int index = Partition(A, start, end);
        printf("%i\n", index);
        q_sort(A, start, index-1);
        q_sort(A, index+1, end);
    }
}

int Partition(int A[], int start, int end)
{
    int i = start + 1, temp;
    int p = rand_pivot(start, end);
    int pivot = A[p];
    // swap with start to be easy
    temp = A[start];
    A[start] = A[p];
    A[p] = temp;

    for (int j = start+1; j <= end; j++)
    {
        if (A[j] < pivot)
        {
            // swap
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            // increment i
            i++;
        }
    }
    // swap the pivot (start) with A[i-1]
    temp = A[start];
    A[start] = A[i-1];
    A[i-1] = temp;

    return i-1;
}

int rand_pivot(int start, int end)
{
    srand(time(0));
    int p = rand() % (end - start + 1) + start;
    return p;
}