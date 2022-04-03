#include <stdio.h>
#include <string.h>

void Add(const char *p1, const char *p2, char *result)
{
    unsigned p1Length = strlen(p1) - 1;
    unsigned p2Length = strlen(p2) - 1;

    unsigned shorter = 0;
    unsigned longer = 0;

    if (p1Length > p2Length)
    {
        longer = p1Length;
        shorter = p2Length;

        for (size_t i = 0; i <= p1Length; i++)
        {
            result[i + 1] = p1[i];
        }
    }
    else
    {
        longer = p2Length;
        shorter = p1Length;

        for (size_t i = 0; i <= p2Length; i++)
        {
            result[i + 1] = p2[i];
        }
    }

    int digit = 0;
    int tempOne = 0;
    for (size_t i = 0; i <= shorter; i++)
    {
        digit = (p1[p1Length - i] - '0') + (p2[p2Length - i] - '0');
        if (tempOne)
        {
            digit++;
            tempOne--;
        }

        if (digit > 9)
        {
            tempOne++;
            result[longer - i + 1] = (digit - 10) + '0';
        }
        else
        {
            result[longer - i + 1] = digit + '0';
        }
    }

    if (tempOne)
    {
        digit = (result[longer - shorter] - '0') + 1;
    }
    else
    {
        digit = (result[longer - shorter] - '0');
    }
    if (digit > 9)
    {
        tempOne++;
        result[longer - shorter] = (digit - 10) + '0';
    }
    else
    {
        result[longer - shorter] = digit + '0';
    }
    result[0] = ' ';
    result[longer + 2] = '\0';
}

int main()
{

    return 0;
}