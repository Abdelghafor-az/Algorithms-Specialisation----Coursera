#include <stdio.h>
#include <stdlib.h>

int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
int ft[] = {6, 2, 0, 7, 1, 4, 8, 3, 5};
int counter = 9;

void swap(int a, int b)
{
    int temp = A[a];
    A[a] = A[b];
    A[b] = temp;
}

int *Sorted_adjLists(void)
{
    int *new = malloc(9 * sizeof(int));
    for (int i = 0; i < 9; i++)
    {
        printf("(%i, %i)\n", i+1, ft[i]+1);
        new[ft[i]] = i+1;
    }

    return new;
}

int main(void)
{
    int *B = Sorted_adjLists();

    for (int i = 0; i < 9; i++)
        printf("%i ", B[i]);
    printf("\n");
}