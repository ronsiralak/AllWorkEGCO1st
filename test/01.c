#include <stdio.h>

int sum(int a, int b)
{
    return a + b;
}

int main()
{
    int x = 3, y = 4;

    if (x < y)
    {
        printf("%d\n", sum(x, y));
    }

    printf("Summation program\n", sum(x, y));
    return 0;
}
