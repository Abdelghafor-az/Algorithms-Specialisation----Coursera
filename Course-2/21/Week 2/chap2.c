#include <stdio.h>

int main(void)
{
    int N, i, j, k;
    printf("Donnez l'hauteur\n");
    scanf("%d", &N);

    for (i = 1; i <= N; i++)
    {
        for (j = 1; j <= N-i; j++)
        {
            printf(" ");
        }
        for (k = 1; k <= i; k++)
        {
            printf("a");
        }
        printf("\n");
    }

    // int N;
    // printf("Donnez l'hauteur de triangle\n");
    // scanf("%d", &N);

    // for (int i = 1; i <= N; i++)
    // {
    //     for (int j = 1; j <= N-i; j++)
    //     { printf(" "); }
    //     for (int e = 1; e <= 2*i-1; e++)
    //     {
    //         printf("*");
    //     }
    //     printf("\n");
    // }
    

    // float S = 0;
    // int N;
    // printf("Donner un terme\n");
    // do
    // {
    //     scanf("%d", &N);
    // }
    // while (N < 1);

    // for (int i = 1; i <= N; i++)
    //     S = S + 1 / (float)i;
    // printf("La somme de la suite harmonique de dernier terme %d est S = %f\n", N, S);
    
    

    // int U1 = 1, U2 = 1, U, N;
    // printf("Donner un terme\n");
    // do
    // {
    //     scanf("%d", &N);
    // }
    // while (N <= 2);

    // for (int i = 0; i < N-2; i++)
    // {
    //     U = U2 + U1;
    //     U1 = U2;
    //     U2 = U;
    // }
    // printf("U%d = %d\n", N, U);

    // int a, b, q, G, N, RES;
    // printf("Donnez la valeur de a et b\n");
    // scanf("%d%d", &a, &b);
    // RES = a > b ? a : b; // est ce que les parentheses va lancer un erreur
    // N = a > b ? b : a;
    // G = RES;
    // // while (RES >= N)
    // // {
    // //     RES = RES - N;
    // //     q++;
    // // }
    // for(q = 0; RES >= N; q++)
    //     RES = RES - N;
    // printf("%d = %dx%d + %d\n", G, N, q, RES);
    

    // int x = 1300200123;
    // float y = 30200123.5; // ......124 different?
    // // max of float is: ?.
    // printf("%d\n", x);
    // printf("%f\n", y);
    // // printf("%lf\n", x*y);

    return 0;
}