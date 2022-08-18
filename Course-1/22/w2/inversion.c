/*               Counting inversions
  - Devide and conquer algorithm for counting array inversion
    based on merge sort
*/

#include <stdio.h>


int count_inversion(int[],int,int,int);
int count_split_inversion(int[], int start, int end);


int main(void)
{
    // printf("Hello Ummah!");
    int A[] = {0,4,5,24,-1,3};
    int len = sizeof(A) / sizeof(int);

    printf("\nThe unsorted array is -> [ ");
    for (int i = 0; i < len; i++)
    {
        printf("%i ", A[i]);
    }
    printf("]\n");

    int inversions = count_inversion(A, 0, len-1, 0);

    printf("The --sorted array is -> [ ");
    for (int i = 0; i < len; i++)
    {
        printf("%i ", A[i]);
    }
    printf("]\nInversions: %d\n", inversions);

    return 0;
}

int count_inversion(int A[], int start, int end, int d)
{
    // base case
    // printf("count_inversion -- start: %d - end: %d - r/l: %d\n", start, end);
    if (start == end)
        return 0;

    int mid = (end + start) / 2;
    // Count left inversion
    int X = count_inversion(A, start, mid,-1);
    // Count right inversion
    int Y = count_inversion(A, mid+1, end, 1);
    // Count splitt inversion
    int Z = count_split_inversion(A, start, end);

    return X + Y + Z;
}

int count_split_inversion(int A[], int start, int end)
{
    // printf("start: %d - end: %d\n", start, end);
    int i, j, mid, size;
    mid = (start + end) / 2;
    i = start; j = mid + 1;
    size = end - start + 1;
    int B[end - start + 1];

    int k, inversions;
    k = inversions = 0;
    while(i <= mid && j <= end)
    {
        if (A[i] < A[j])
            B[k++] = A[i++];
        else {
            B[k++] = A[j++];
            inversions += mid - i + 1;
        }
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

    return inversions;
}
