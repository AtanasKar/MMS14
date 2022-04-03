#include <stdio.h>

void Conv(int sValue, char *pBuffer)
{
    if (sValue < 0)
    {
        pBuffer[0] = '-';
        sValue *= -1;
    }
    else
    {
        pBuffer[0] = ' ';
    }

    for (int i = 5; i > 0; i--)
    {
        if (sValue != 0)
        {
            pBuffer[i] = '0' + sValue % 10;
            sValue /= 10;
        }
        else
        {
            pBuffer[i] = ' ';
        }
    }
    pBuffer[6] = '\0';
}

int main()
{
    char buffer[7];

    Conv(-26, buffer);

    printf("%s\n", buffer);

    return 0;
}