#include <stdio.h>
#include <string.h>

int main()
{
    char bigNum[500];

    scanf("%s",bigNum);

    int digit;

    for (size_t i = 0; i < strlen(bigNum); i++)
    {
        sscanf(bigNum[i],"%d",&digit);
        
        if (i % 2 == 0)
        {
            bigNum[i] = digit + 'A';
        }
        else
        {
            switch (digit)
            {
            case 0:
                bigNum[i] = '!';
                break;
            case 1:
                bigNum[i] = '#';
                break;
            case 2:
                bigNum[i] = '/';
                break;
            case 3:
                bigNum[i] = '~';
                break;
            case 4:
                bigNum[i] = '=';
                break;
            case 5:
                bigNum[i] = '\'';
                break;
            case 6:
                bigNum[i] = '\\';
                break;
            case 7:
                bigNum[i] = '>';
                break;
            case 8:
                bigNum[i] = '.';
                break;
            case 9:
                bigNum[i] = ',';
                break;
            }
        }
    }

    printf("%s\n",bigNum);
    return 0;
}