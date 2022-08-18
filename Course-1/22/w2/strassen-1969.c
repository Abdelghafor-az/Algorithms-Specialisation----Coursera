/*          Strassen-1969
    Devide and Conquer Algorithm for
        Matrix Multiplication
*/ 

#include <stdio.h>
#include <stdlib.h>

// #define N 2

struct arr2D {
    int M[2][2];
};

void print_matrix(int n,int[n][n]);
struct arr2D MADD(int n,int[n][n],int[n][n]);
struct arr2D MSUB(int n,int[n][n],int[n][n]);


int main(void)
{
    int n = 2;
    int A[2][2] = {{1,44}, {0,2}};
    int B[2][2] = {{1,44}, {0,2}};

    // print_matrix(2, A);
    struct arr2D C =  MADD(n, A, B);
    struct arr2D D =  MSUB(n, C.M, A);
    print_matrix(n, C.M);
    print_matrix(n, D.M);

    return 0;
}

void print_matrix(int n, int A[n][n])
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%3d ", A[i][j]);
            // printf("%3d ", *(*(A+i)+j));
        }
        printf("\n");
    }
    return;
}

struct arr2D MADD(int n, int A[][n], int B[][n])
{
    struct arr2D C;
    // C = malloc(sizeof(int*) * n); 
    // for(int i = 0; i < 3; i++) { 
    //     C[i] = malloc(sizeof(int) * n);
    // } 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            C.M[i][j] = A[i][j] + B[i][j];
    }

    return C;
}

struct arr2D MSUB(int n, int A[][n], int B[][n])
{
    struct arr2D C;
    // C = malloc(sizeof(int*) * n); 
    // for(int i = 0; i < 3; i++) { 
    //     C[i] = malloc(sizeof(int) * n);
    // }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            C.M[i][j] = A[i][j] - B[i][j];
    }

    return C;
}

struct arr2D Iterative_methode(int n, int A[][n], int B[][n])
{
    struct arr2D C;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            C.M[i][j] = A[i][j] * B[i][j];
    }

    return C;
}
