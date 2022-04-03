#include <stdio.h>

unsigned int BinSearch(unsigned int *pArray, unsigned int uArraySize, unsigned int uValue)
{
    int low = 0;
    int high = uArraySize - 1;
    int mid = (low + high) / 2;
    
    while (low != high)
    {
        if (pArray[mid] == uValue)
        {
            return mid;
        }
        else if (pArray[mid] > uValue)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
        mid = (low + high) / 2;
    }

    if (pArray[mid] == uValue)
    {
        return mid;
    }
    return 0xFFFF;
}

int main()
{

    return 0;
}