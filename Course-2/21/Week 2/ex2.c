#include <stdio.h>

int main()
{
    int U, min, max;
    printf("Donner une serie de nombres\n");
    scanf("%d", &U);

    max = U, min = U;
    while (U != 0)
    {
        if (U > max)
            max = U;
        if (U < min)
            min = U;
        scanf("%d", &U);
    }
    printf("max = %d et min = %d\n", max, min);

    return 0;
}