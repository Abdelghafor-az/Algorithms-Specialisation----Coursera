// Merge Sort: divide until the base case - merge
#include <stdio.h>

void merge_sort(int A[], int start, int end);
void merge(int A[], int start, int mid, int end);

int main(void)
{
    int A[] = {5, 2, 7, 8, 4, 1, 6, 3};
    int length = sizeof(A) / sizeof(A[0]);
    printf("The unsorted array is -> [ ");
    for (int i = 0; i < length; i++)
    {
        printf("%i ", A[i]);
    }
    printf("]\n");

    merge_sort(A, 0, length-1);

    printf("The sorted array is -> [ ");
    for (int i = 0; i < length; i++)
    {
        printf("%i ", A[i]);
    }
    printf("]\n");

}

void merge_sort(int A[], int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;

        merge_sort(A, start, mid);
        merge_sort(A, mid+1, end);
        merge(A, start, mid, end);
    }
}

void merge(int A[], int start, int mid, int end)
{
    int C[end - start + 1];
    int i = start, j = mid + 1, k = 0;
    while(i <= mid && j <= end)
	{
		if (A[i] <= A[j])
			C[k++] = A[i++];
		else
			C[k++] = A[j++];
    }

    while( i <= mid )
		C[k++]=A[i++];

	while( j <= end )
		C[k++]=A[j++];

    k = 0;
	for(i = start; i <= end ; i++)
		A[i]=C[k++];
}

