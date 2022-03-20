#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

unsigned onesCount(unsigned count, size_t size, ...);

int main()
{
    int a = 0b0111, b = 0b1110;

    printf("%u\n", onesCount(2, sizeof(int) * 8, a, b));

    return EXIT_SUCCESS;
}

unsigned onesCount(unsigned count, size_t size, ...)
{
    unsigned cnt = 0;

    va_list ap;
    va_start(ap, size);

    for (size_t i = 0; i < count; i++)
    {
        int mask = va_arg(ap, int);
        for (size_t j = 0; j < size; j++)
        {
            cnt += !!(mask & (1 << j));
            // printf("%u",cnt);
        }
    }
    va_end(ap);

    return cnt;
}