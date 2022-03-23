#include <stdio.h>

double mySqrt(double num);

int main()
{
    double number;
    scanf("%lf", &number);

    double sqrt = mySqrt(number);

    if (sqrt == -1)
    {
        fprintf(stderr, "Negative number!\n");
        return -1;
    }
    printf("%lf\n", sqrt);

    return 0;
}

double mySqrt(double num)
{
    if (num < 0)
    {
        return -1;
    }

    double sqrt = num / 2;
    unsigned accuracy = 10;

    while (sqrt && accuracy--)
    {
        sqrt = (num / sqrt + sqrt) / 2;
    }

    return sqrt;
}