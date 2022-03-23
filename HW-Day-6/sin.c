#include <stdio.h>
#define PI 3.14159265359

int main()
{
    double number;
    scanf("%lf", &number);

    double radians = number / 180 * PI;

    unsigned accuracy = 5;
    unsigned pow = 1;
    int sign = 1;
    unsigned factorialStep = 1;
    double sine = 0;

    while (radians && accuracy--)
    {
        double poweredSin = radians;
        for (size_t i = 1; i < pow; i++)
        {
            poweredSin *= radians;
        }

        unsigned factorial = 1;
        for (size_t i = 1; i <= factorialStep; i++)
        {
            factorial *= i;
        }

        sine += poweredSin * sign / factorial;

        pow += 2;
        factorialStep += 2;
        sign *= -1;
    }

    printf("%lf\n", sine);

    return 0;
}