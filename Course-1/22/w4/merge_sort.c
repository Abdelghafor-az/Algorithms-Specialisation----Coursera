#include "merge_sort.h"

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
