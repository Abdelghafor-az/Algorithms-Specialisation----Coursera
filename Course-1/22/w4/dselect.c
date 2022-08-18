#include <stdio.h>

#include "merge_sort.h"

int Dselect(int[],int,int,int);
void print_arr(int A[], int len);

int main(void)
{
    int A[] = {123,53,-31,2,0,90};
    int len = sizeof(A) / sizeof(int);

    print_arr(A, len);
    merge_sort(A, 0, len-1);
    print_arr(A, len);
}

int Dselect(int A[], int start, int end, int ith)
{
    int B[5], C[(end-start) / 5];
    for (int i = 0; i <= end; i += 5)
    {
        B[i%5] = A[i];
    }
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