/*               Merge Sort
  - Devide and conquer Sorting algorithm
*/

#include <stdio.h>


void merge_sort(int[],int,int);
void merge(int[], int start, int end);


int main(void)
{
    // printf("Hello Ummah!");
    // int A[] = {0,4,5,24,-1,3};
    int A[] = {123,53,-31,2,0,90};
    int len = sizeof(A) / sizeof(int);

    printf("\nThe unsorted array is -> [ ");
    for (int i = 0; i < len; i++)
    {
        printf("%i ", A[i]);
    }
    printf("]\n");

    merge_sort(A, 0, len-1);

    printf("The sorted array is -> [ ");
    for (int i = 0; i < len; i++)
    {
        printf("%i ", A[i]);
    }
    printf("]\n");

    return 0;
}

void merge_sort(int A[], int start, int end)
{
    // base case
    // printf("merge_sort -- start: %d - end: %d - r/l: %d\n", start, end);
    if (start == end)
        return;

    int mid = (end + start) / 2;
    // Sort the left half
    merge_sort(A, start, mid);
    // Sort the right half
    merge_sort(A, mid+1, end);
    // merge the two halfs
    merge(A, start, end);
}

void merge(int A[], int start, int end)
{
    // printf("start: %d - end: %d\n", start, end);
    int i, j, mid, size;
    mid = (start + end) / 2;
    i = start; j = mid + 1;
    size = end - start + 1;
    int B[end - start + 1];

    int k = 0;
    while(i <= mid && j <= end)
    {
        if (A[i] < A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }
    while (i <= mid)
    {
        B[k++] = A[i++];
    }
    while (j <= end)
    {
        B[k++] = A[j++];
    }

    // copy the Sorted array into original
    i = start;
    for (k = 0; k < size; k++)
        A[i++] = B[k];

    return;
}
