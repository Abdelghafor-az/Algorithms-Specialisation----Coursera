// Divide & Conquer Algorithm for Matrix Multiplication

// main - alg - addition - combine all in one big matrix - osalamuaalaykom

#include <stdio.h>
#include <stdlib.h>


int **MM(int **X, int **Y, int N);
int **MADD(int **A, int **B, int N);
int **MSUB(int **A, int **B, int N);
int **pattern(int N);
int **fill_m(int **M, int p[]);
int **Combine(int **Blocks[], int N);
void free_(int**n[], int l);
void print(int **M, int N);

int main(void)
{
    // int N = 2;
    int N = 3;

    int **A = malloc(sizeof(int*) * N);
    for (int i = 0; i < N; i++)
        A[i] = (int *)malloc(N * sizeof(int));

    int **B = malloc(sizeof(int*) * N);
    for (int i = 0; i < N; i++)
        B[i] = (int *)malloc(N * sizeof(int));

    // A[0][0] = 1; A[0][1] = 2; A[0][2] = 1; A[0][3] = 1;
    // A[1][0] = 1; A[1][1] = 0; A[1][2] = 1; A[1][3] = 0;
    // A[2][0] = 1; A[2][1] = 2; A[2][2] = 0; A[2][3] = 2;
    // A[3][0] = 2; A[3][1] = 0; A[3][2] = 1; A[3][3] = 2;

    // B[0][0] = 1; B[0][1] = 1; B[0][2] = 1; B[0][3] = 0;
    // B[1][0] = 2; B[1][1] = 2; B[1][2] = 1; B[1][3] = 2;
    // B[2][0] = 0; B[2][1] = 1; B[2][2] = 2; B[2][3] = 0;
    // B[3][0] = 0; B[3][1] = 0; B[3][2] = 2; B[3][3] = 1;

    A[0][0] = 1; A[0][1] = 2; A[0][2] = 1;
    A[1][0] = 1; A[1][1] = 0; A[1][2] = 1;
    A[2][0] = 1; A[2][1] = 2; A[2][2] = 0;

    B[0][0] = 1; B[0][1] = 1; B[0][2] = 1;
    B[1][0] = 2; B[1][1] = 2; B[1][2] = 1;
    B[2][0] = 0; B[2][1] = 1; B[2][2] = 2;

    // int A[4][4] = {
    //     {1,2,1,1}, {1,0,1,0}, {1,2,0,2}, {2,0,1,2}
    // };
    // int B[4][4] = {
    //     {1,1,1,0}, {2,2,1,2}, {0,1,2,0}, {0,0,2,1}
    // };

    // A[0][0] = 1; A[0][1] = 2; A[1][0] = 1; A[1][1] = 0;
    // B[0][0] = 1; B[0][1] = 1; B[1][0] = 2; B[1][1] = 2;

    int **result;
    result = MM(A, B, N);

    for (int i = 0; i < N; i++)
    {
        printf("|");
        for (int j = 0; j < N; j++)
        {
            printf(" %i ", result[i][j]);
        }
        printf("|\n");
    }

    free(result);
    free(A); free(B);
    return 0;
}

// Matrix Multiplication
int **MM(int **X, int **Y, int N) // compiler Not compatible with C99 (A[][N] Not Allowed)
{
    if (N <= 2)
    {
        // printf("| %i  %i |\n| %i  %i |\n", X[0][0], X[0][1], X[1][0], X[1][1]);
        // printf("| %i  %i |\n| %i  %i |\n", Y[0][0], Y[0][1], Y[1][0], Y[1][1]);
        int a = X[0][0] * Y[0][0] + X[0][1] * Y[1][0];
        int b = X[0][0] * Y[0][1] + X[0][1] * Y[1][1];
        int c = X[1][0] * Y[0][0] + X[1][1] * Y[1][0];
        int d = X[1][0] * Y[0][1] + X[1][1] * Y[1][1];
        // printf("%i %i %i %i\n", a, b, c, d);
        // printf("\n| %i  %i |\n| %i  %i |\n ------ \n", a, b, c, d);

        int **Matrix;
        Matrix = malloc(sizeof(int*) * 2); // -> 8
        for (int i = 0; i < 2; i++)
            Matrix[i] = (int *)malloc(2 * sizeof(int));
        Matrix[0][0] = a;
        Matrix[0][1] = b;
        Matrix[1][0] = c;
        Matrix[1][1] = d;
        // printf("| %i  %i |\n| %i  %i |\n ------ \n", Matrix[0][0], Matrix[0][1], Matrix[1][0], Matrix[1][1]);
        // printf("| %i  %i |\n| %i  %i |\n ------ \n", a, b, c, d);

        // return NULL;
        return Matrix;
    }

    printf("================\n");

    int **ij = pattern(N/2);

    int **P[7];
    int **Blocks[4];
    int **A, **B, **C, **D, **E, **F, **G, **H;
    int **F_H, **AB, **CD, **G_E, **AD, **EH, **B_D, **GH, **A_C, **EF;

    A = fill_m(X, ij[0]); B = fill_m(X, ij[1]);
    C = fill_m(X, ij[2]); D = fill_m(X, ij[3]);
    E = fill_m(Y, ij[0]); F = fill_m(Y, ij[1]);
    G = fill_m(Y, ij[2]); H = fill_m(Y, ij[3]);

    F_H = MSUB(F, H, N/2);
    P[0] = MM(A, F_H, N/2);

    AB = MADD(A, B, N/2);
    P[1] = MM(AB, H, N/2);

    CD = MADD(C, D, N/2);
    P[2] = MM(CD, E, N/2);

    G_E = MSUB(G, E, N/2);
    P[3] = MM(D, G_E, N/2);

    AD = MADD(A, D, N/2); EH = MADD(E, H, N/2);
    P[4] = MM(AD, EH, N/2);

    B_D = MSUB(B, D, N/2); GH = MADD(G, H, N/2);
    P[5] = MM(B_D, GH, N/2);

    A_C = MSUB(A, C, N/2); EF = MADD(E, F, N/2);
    P[6] = MM(A_C, EF, N/2);


    int **P4_2 = MSUB(P[3], P[1], N/2);
    int **P54_2 = MADD(P[4], P4_2, N/2);
    Blocks[0] = MADD(P54_2, P[5], N/2);
    // print(Blocks[0], N/2);

    Blocks[1] = MADD(P[0], P[1], N/2);
    // print(Blocks[1], N/2);

    Blocks[2] = MADD(P[2], P[3], N/2);
    // print(Blocks[2], N/2);

    int **P15 = MADD(P[0], P[4], N/2);
    int**P15_3 = MSUB(P15, P[2], N/2);
    Blocks[3] = MSUB(P15_3, P[6], N/2);
    // print(Blocks[3], N/2);
    // return NULL;

    int **MATRIX = Combine(Blocks, N);

    // free(indexes); free(matrices); free(Blocks) with code (iterate) ?
    int **names[] = {A, B, C, D, E, F, G, H};
    int **operations[] = {F_H, AB, CD, G_E, AD, EH, B_D, GH, A_C, EF};
    free_(names, 8);
    free_(operations, 10);
    free_(Blocks, 4);
    // free_(ij, 4);
    // free_(Blocks[0], 4);
    // free_(Blocks[2], 4); free_(Blocks[3], 4);
    // return NULL;
    return MATRIX;
}

// Matrix Addition
int **MADD(int **A, int **B, int N)
{
    int **C;
    C = malloc(sizeof(int*) * N);
    for (int i = 0; i < N; i++)
    {
        C[i] = (int *)malloc(N * sizeof(int));
        for (int j = 0; j < N; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
            // printf(" %i ", C[i][j]);
        }
        // printf("\n");
    }
    // printf("| %i  %i |\n| %i  %i |\n ------ \n", C[0][0], C[0][1], C[1][0], C[1][1]);

    return C;
}

int **MSUB(int **A, int **B, int N)
{
    // printf("| %i  %i |\n| %i  %i |\n", A[0][0], A[0][1], A[1][0], A[1][1]);
    // printf("| %i  %i |\n| %i  %i |\n", B[0][0], B[0][1], B[1][0], B[1][1]);

    int **D;
    D = malloc(sizeof(int*) * N);
    for (int i = 0; i < N; i++)
    {
        D[i] = (int *)malloc(N * sizeof(int));
        for (int j = 0; j < N; j++)
        {
            D[i][j] = A[i][j] - B[i][j];
            // printf("%i ", D[i][j]);
            // printf("%i - %i = %i |", A[i][j], B[i][j], D[i][j]);
        }
        // printf("\n");
    }

    return D;
}

int **pattern(int N)
{
    int index[4][3] = {
        {0, 0, N}, {0, N, N}, {N, 0, N}, {N, N, N}
    };

    int **ij;
    ij = malloc(sizeof(int*) * 4);
    for (int i = 0; i < 4; i++)
    {
        ij[i] = (int *)malloc(sizeof(int) * 3);
        for (int j = 0; j < 3; j++)
        {
            ij[i][j] = index[i][j];
            // printf("%i ", ij[i][j]);
        }
        // printf("\n");
        // printf("--------\n");
    }

    return ij;
}

int **fill_m(int **M, int p[])
{
    int **matrix;
    matrix = malloc(sizeof(int*) * p[2]);
    for (int i = 0; i < p[2]; i++)
    {
        matrix[i] = (int *)malloc(p[2] * sizeof(int));
        for (int j = 0; j < p[2]; j++)
        {
            matrix[i][j] = M[i+p[0]][j+p[1]];
            // printf(" %i, %i = %i |", i, j, matrix[i][j]);
        }
        // printf("\n");
    }

    return matrix;
}

int **Combine(int **Blocks[], int N)
{
    int k = N/2;
    int **Mm = malloc(sizeof(int*) * N);
    for (int i = 0; i < N; i++)
        Mm[i] = (int *)malloc(N * sizeof(int));

    // printf("N: %i\n", N);
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            // printf("i: %i - j: %i\n", i, j);
            Mm[ i ][ j ] = Blocks[0][i][j];
            Mm[i][j + k] = Blocks[1][i][j];
            Mm[i + k][j] = Blocks[2][i][j];
            Mm[i+k][j+k] = Blocks[3][i][j];
        }
    }

    return Mm;
}

// how to pass multiple arguments for data types
void free_(int**n[], int l)
{
    for (int m = 0; m < l; m++)
    {
        free(n[m]);
    }
}

void print(int **M, int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%i ", M[i][j]);
            // printf("miii\n");
        }
        printf("\n");
    }
}