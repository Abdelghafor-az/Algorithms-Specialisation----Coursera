#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rselect(int A[], int start, int end, int i);
int Partition(int A[], int start, int end);
int rand_pivot(int start, int end);
void swap(int A[], int a, int b);

int main(void) {
    int A[] = {3, 8, 2, 1, 7, 33, 234, 533, 23, 12, 10};
    int length = sizeof(A) / sizeof(A[0]);

    int i = 11;
    int order_statistique = rselect(A, 0, length - 1, i-1);
    printf("%i is %ith order statistique\n", order_statistique, i);

    return 0;
}

int rselect(int A[], int start, int end, int i)
{
    int n = end - start + 1;
    if (n <= 1)
        return A[end];

    int j = Partition(A, start, end); // 1
    printf("j:%i\n", j);
    if (j == i)
        return A[j];
    if (j > i)
    {
        // recurse on the left side
        return rselect(A, start, j-1, i);
    }
    else
    {
        // recurse on the right side
        return rselect(A, j+1, end, i);
    }
}

int Partition(int A[], int start, int end)
{
    int i = start + 1;
    int p = rand_pivot(start, end);
    swap(A, start, p);
    int pivot = A[start];

    for (int j = start+1; j <= end; j++)
    {
        if (A[j] < pivot) {
            swap(A, i, j);
            i++;
        }
    }
    // swap the pivot A[start] with A[i-1]
    swap(A, start, i-1);

    return i-1;
}

int rand_pivot(int start, int end)
{
    srand(time(0));
    int pivot = rand() % (end - start + 1) + start;
    return pivot;
}

void swap(int A[], int a, int b)
{
    int temp = A[a];
    A[a] = A[b];
    A[b] = temp;
}