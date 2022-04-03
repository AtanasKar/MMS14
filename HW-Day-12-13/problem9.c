#include <stdio.h>
#include <string.h>

void SPRINTF(char *szBuffer, char *szPattern, char **args)
{
    int argCnt = 0;
    size_t i = 0;
    size_t bufferIndex = 0;
    while (szPattern[i] != '\0')
    {
        if (szPattern[i] == '%' && szPattern[i + 1] == 's')
        {
            size_t j = 0;
            while (args[argCnt][j] != '\0')
            {
                szBuffer[i + j] = args[argCnt][j];
                j++;
            }

            i +=2;
            bufferIndex += (j-1);
            argCnt++;
            continue;
        }

        szBuffer[bufferIndex] = szPattern[i];
        bufferIndex++;
        i++;
    }
    szBuffer[bufferIndex] = '\0';
}

int main()
{
    char buffer[50];
    char *args[] = {"Arg1", "Arg2"};

    SPRINTF(buffer, "This func takes %s and %s as arguments\n", args);

    //printf("%s", buffer);

    return 0;
}