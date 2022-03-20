#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int triangle(double, double, double, double *, double *);

int main()
{
    double a, b, c;
    scanf("%lf %lf %lf", &a, &b, &c);

    double per = 0, area = 0;

    if (triangle(a, b, c, &per, &area) != 0)
    {
        fprintf(stderr, "Ivalid triangle sides!\n");
        return EXIT_FAILURE;
    }
    else
    {
        printf("S: %.2lf\nP: %.2lf\n", area, per);
    }

    return EXIT_SUCCESS;
}

int triangle(double a, double b, double c, double *per, double *area)
{
    if (a <= 0 || b <= 0 || c <= 0 || a + b <= c || a + c <= b || b + c <= a)
    {
        return -1;
    }

    *per = a + b + c;

    double p = *per / 2;

    *area = sqrt(p * (p - a) * (p - b) * (p - c));

    return 0;
}