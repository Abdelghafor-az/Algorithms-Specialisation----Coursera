// Divide & Conquer Algorithm for Matrix Multiplication

// main - alg - addition - combine all in one big matrix - osalamuaalaykom

#include <stdio.h>
#include <stdlib.h>

const int M = 4;

int **MM(int A[][M], int B[][M], int base[], int N);
int **MADD(int **A, int **B, int N);
// int **MADD(int *A, int *B, int N);
int **update(int base[], int N);
int **Combine(int **Blocks[], int N);

int main(void)
{
    int N = 4;
    int A[4][4] = {
        {1, 2, 1, 1}, {1, 0, 1, 0},
        {1, 2, 0, 2}, {2, 0, 1, 2}
    };

    int B[4][4] = {
        {1, 1, 1, 0}, {2, 2, 1, 2},
        {0, 1, 2, 0}, {0, 0, 2, 1}
    };

    int base[] = {0, 0, 0, 0};
    int **result;
    result = MM(A, B, base, N);

    for (int i = 0; i < N; i++)
    {
        printf("|");
        for(int j = 0; j < N; j++)
        {
            printf(" %i ", result[i][j]);
        }
        printf("|\n");
    }

    // Global N or concept of pointers
    free(result);
    return 0;
}

// Matrix Multiplication
int **MM(int A[][M], int B[][M], int base[], int N) // compiler Not compatible with C99 (A[][N] Not Allowed)
{
    // I need another argument and maybe two for each to know what submatrices I have to multiply
    if (N <= 2)
    {
        int ai = base[0]; int aj = base[1];
        int bi = base[2]; int bj = base[3];
        // printf("A:(%i, %i) B:(%i, %i)\n", ai, aj, bi, bj);

        int a = A[ai][aj] * B[bi][bj] + A[ai][aj+1] * B[bi+1][bj];
        int b = A[ai][aj] * B[bi][bj+1] + A[ai][aj+1] * B[bi+1][bj+1];
        int c = A[ai+1][aj] * B[bi][bj] + A[ai+1][aj+1] * B[bi+1][bj];
        int d = A[ai+1][aj] * B[bi][bj+1] + A[ai+1][aj+1] * B[bi+1][bj+1];
        // printf("%i %i %i %i\n", a, b, c, d);
        // printf("| %i  %i |\n| %i  %i |\n ------ \n", a, b, c, d);
        int **Matrix;
        Matrix = malloc(sizeof(int*) * 2); // -> 8
        for (int i = 0; i < 4; i++)
            Matrix[i] = (int *)malloc(2 * sizeof(int));
        Matrix[0][0] = a;
        Matrix[0][1] = b;
        Matrix[1][0] = c;
        Matrix[1][1] = d;
        // printf("| %i  %i |\n| %i  %i |\n ------ \n", Matrix[0][0], Matrix[0][1], Matrix[1][0], Matrix[1][1]);

        return Matrix;
    }

    int **indexes = update(base, N/2);

    // printf("================\n");

    int **matrices[8];
    int **Blocks[4];

    matrices[0] = MM(A, B, indexes[0], N/2);
    matrices[1] = MM(A, B, indexes[1], N/2);
    Blocks[0] = MADD(matrices[0], matrices[1], N/2);
    // printf("Blocks is indexablw (what is this word) %i\n", Blocks[0][0][1]);


    matrices[2] = MM(A, B, indexes[2], N/2);
    matrices[3] = MM(A, B, indexes[3], N/2);
    Blocks[1] = MADD(matrices[2], matrices[3], N/2);


    matrices[4] = MM(A, B, indexes[4], N/2);
    matrices[5] = MM(A, B, indexes[5], N/2);
    Blocks[2] = MADD(matrices[4], matrices[5], N/2);


    matrices[6] = MM(A, B, indexes[6], N/2);
    matrices[7] = MM(A, B, indexes[7], N/2);
    Blocks[3] = MADD(matrices[6], matrices[7], N/2);

    int **MATRIX = Combine(Blocks, N);

    // free(matrices); free(Blocks) with code (iterate) ?
    return MATRIX;
}

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

int **update(int base[], int N)
{
    int updates[8][4] = {
        {0, 0, 0, 0}, {0, N, N, 0}, {0, 0, 0, N}, {0, N, N, N},
        {N, 0, 0, 0}, {N, N, N, 0}, {N, 0, 0, N}, {N, N, N, N}
    };

    int **indexes;
    indexes = malloc(sizeof(int*) * 8);
    for (int i = 0; i < 8; i++)
    {
        indexes[i] = (int *)malloc(4 * sizeof(int));
        for (int j = 0; j < 4; j++)
        {
            indexes[i][j] = base[j];
            indexes[i][j] += updates[i][j];
            // printf("%i ", indexes[i][j]);
        }
        // printf("\n");
    }

    return indexes;
}

int **Combine(int **Blocks[], int N)
{
    int **Mm; int k = N/2;
    Mm = malloc(sizeof(int*) * N);
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