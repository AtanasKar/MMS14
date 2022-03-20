#include <stdio.h>
#include <stdlib.h>
#include <math.h>

unsigned numLength(unsigned number)
{
    unsigned cnt = 0;
    while (number != 0)
    {
        number /= 10;
        cnt++;
    }
    return cnt;
}

unsigned baseNumLength(unsigned base, unsigned num)
{
    unsigned cnt = 0;
    while (num != 0)
    {
        num /= base;
        cnt++;
    }
    return cnt;
}

int main()
{
    unsigned number, firstBase, secondBase;
    scanf("%u %u %u", &number, &firstBase, &secondBase);

    if ((firstBase < 2 || firstBase > 36) && (secondBase < 2 || secondBase > 36))
    {
        fprintf(stderr, "Invalid base!");
        return EXIT_FAILURE;
    }

    unsigned decimal = 0;
    unsigned numberCpy = number;
    for (size_t i = 0; i < numLength(number); i++)
    {
        decimal += (numberCpy % 10) * pow(firstBase, i);
        numberCpy /= 10;
    }

    printf("%d\n", decimal);

    unsigned result = 0;

    for (size_t i = 0, j = 1; decimal != 0; i++)
    {
        if (i == 0)
        {
            result += decimal % secondBase;
            decimal /= secondBase;
            continue;
        }

        j *= 10;
        result += (decimal % secondBase) * j;
        decimal /= secondBase;
    }

    printf("%d\n", result);

    return EXIT_SUCCESS;
}