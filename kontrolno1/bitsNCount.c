#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

unsigned bitsNCount(unsigned, unsigned, ...);

int main()
{
    printf("%u\n",bitsNCount(5,10,0x0a,0xa0ff,0,10,0b1010111110111));

    return EXIT_SUCCESS;
}

unsigned bitsNCount(unsigned count, unsigned bitscnt, ...)
{
    int cnt = 0;

    va_list masks;
    va_start(masks, bitscnt);

    for (size_t i = 0; i < count; i++)
    {
        int curMask = va_arg(masks, int);
        unsigned curMaskBitsCnt = 0;
        for (size_t j = 0; j < sizeof(curMask) * 8; j++)
        {
            curMaskBitsCnt += !!(curMask & (1 << j));
        }
        if (curMaskBitsCnt == bitscnt)
        {
            cnt++;
        }
    }
    va_end(masks);

    return cnt;
}
