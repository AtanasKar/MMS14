#include <stdio.h>
#include <stdint.h>

int clearBit(uint32_t *maskArr, size_t nitems, size_t bit)
{
    if (bit < 0 || bit >= 32 || nitems <= 0 || maskArr == NULL)
    {
        return -1;
    }
    for (size_t i = 0; i < nitems; i++)
    {
        maskArr[i] &= ~(1 << bit);
    }
}

int setBit(uint32_t *maskArr, size_t nitems, size_t bit)
{
    if (bit < 0 || bit >= 32 || nitems <= 0 || maskArr == NULL)
    {
        return -1;
    }
    for (size_t i = 0; i < nitems; i++)
    {
        maskArr[i] |= (1 << bit);
    }
}

int checkBit(uint32_t *maskArr, size_t len, size_t bit)
{
    if (bit < 0 || bit >= 32 || len <= 0 || maskArr == NULL)
    {
        return -1;
    }
    return  maskArr[len] &= (1 << bit);
    
}

int main()
{
    
    return 0;
}