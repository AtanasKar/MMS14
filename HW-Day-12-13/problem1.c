#include <stdio.h>

unsigned char CheckBit(unsigned int uValue)
{
    unsigned cnt = 0;
    for (size_t i = 0; i < 16; i++)
    {
        if (uValue & (1 << i))
        {
            cnt++;
        }
        if (cnt > 1)
        {
            return 0;
        }
    }
    return !!cnt;
}

int main()
{
    unsigned input = 0x0600;

    printf("%u\n", CheckBit(input));
    return 0;
}