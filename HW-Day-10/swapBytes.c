#include <stdio.h>
#include <stdint.h>

void swapByte(uint16_t *);


int main()
{
    uint16_t word;
    scanf("%hu",&word);

    swapByte(&word);

    printf("Swaped: %u\n", word);

    return 0;
}

void swapByte(uint16_t *word)
{
    uint16_t temp1 = *word & 1;

    unsigned cnt = 0;
    uint16_t tempWord = *word;
    while (tempWord)
    {
        tempWord /= 2;
        cnt++;
    }

    *word = *word | 1;
    if (!temp1)
    {
        *word &= ~(1 << cnt - 1);
    }
}