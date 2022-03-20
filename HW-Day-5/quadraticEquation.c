#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int quadEq(double, double, double, double *, double *);

int main()
{
    double a, b, c;
    scanf("%lf %lf %lf", &a, &b, &c);

    double x1 = 0, x2 = 0;

    if (quadEq(a, b, c, &x1, &x2) == 0)
    {
        printf("x1: %.2lf\nx2: %.2lf\n", x1, x2);
    }
    else if (quadEq(a, b, c, &x1, &x2) == 1)
    {
        printf("x1: %.2lf\nP", x1);
    }
    else
    {
        fprintf(stderr, "No real roots!\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

int quadEq(double a, double b, double c, double *x1, double *x2)
{
    double D = b * b - 4 * a * c;

    if (D < 0)
    {
        return -1;
    }
    else if (D == 0)
    {
        *x1 = -1 * b / 2 * a;
        return 1;
    }

    *x1 = (-1 * b + sqrt(D)) / (2 * a);
    *x2 = (-1 * b - sqrt(D)) / (2 * a);

    return 0;
}