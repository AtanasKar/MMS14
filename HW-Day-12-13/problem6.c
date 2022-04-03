#include <stdio.h>

void Bubble(int *pArray, unsigned int uLen)
{
    int temp = 0;
    for (size_t i = 0; i < uLen - 1; i++)
    {
        for (size_t j = i; j < uLen - 1; j++)
        {
            if (pArray[j] > pArray[j + 1])
            {
                temp = pArray[j];
                pArray[j] = pArray[j + 1];
                pArray[j + 1] = temp;
            }
        }
    }
}

int main()
{
    
    return 0;
}