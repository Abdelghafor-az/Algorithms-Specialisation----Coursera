#include <stdio.h>

int Count(int A[], int start, int end);
int CountSplitInv(int A[], int start, int mid, int end);

int main(void)
{
    int A[] = {1, 4, 3, 2, 5, 6};
    // int A[] = {5, 2, 7, 8, 4, 1, 6, 3};
    // int A[] = {5, 6, 8, 7};
    int length = sizeof(A) / sizeof(A[0]);
    printf("The unsorted array is -> [ ");
    for (int i = 0; i < length; i++)
    {
        printf("%i ", A[i]);
    }
    printf("]\n");

    int inversions = Count(A, 0, length-1);

    printf("The sorted array is -> [ ");
    for (int i = 0; i < length; i++)
    {
        printf("%i ", A[i]);
    }
    printf("]\n");
    // printf("%i - %i\n", Inv, c);
    printf("The number of inversions is %i\n", inversions);
    return 0;
}

int Count(int A[], int start, int end)
{
    int Inv = 0, mid;
    if (start < end)
    {
        mid = (start + end) / 2;
        Inv += Count(A, start, mid);
        Inv += Count(A, mid+1, end);
        Inv += CountSplitInv(A, start, mid, end);
    }
    return Inv;
}

int CountSplitInv(int A[], int start, int mid, int end)
{
    int Inv = 0;
    int C[end - start + 1];
    int size = end - start + 1;
    int i = start, j = mid + 1, k = start;
    while(i <= mid && j <= end)
	{
		if (A[i] <= A[j])
		{
			C[k++] = A[i++];
		}
		else
		{
			C[k++] = A[j++];
		    //  printf("%i - %i\n", (size / 2) - i + start, mid - i);
            // Inv += size - (size / 2) - i + start; // what, If i don't increment we're fine, if we do -> problem
            // How ? I don't hacking know
            // Hohooo! If I don't print It goes alright
            Inv += mid - i + 1;
		}
// 		Inv += (size / 2) - i + start;
    }

    while( i <= mid )
		C[k++]=A[i++];
// 		Inv++;

	while( j <= end )
		C[k++]=A[j++];

	for(i = start; i <= end ; i++)
		A[i]=C[i];

	for(i = start; i <= end ; i++)
		A[i]=C[i];

	return Inv;
}
