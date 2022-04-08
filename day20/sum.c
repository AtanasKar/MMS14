#include <stdio.h>
#include <stdlib.h>
int main()
{

    int sum = 0, N=20000;
    //scanf("%d", &N);
    for (size_t i = 1; i <= N; i++)
    {
        for (size_t i = 1; i <= N; i++)
        {
            sum += i;
        }
    }

    printf("Sum end: %d\n", sum);
    exit(0);
}