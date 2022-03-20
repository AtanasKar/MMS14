#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int rectangle(double, double, double *, double *);

int main()
{
    double a, b;
    scanf("%lf %lf", &a, &b);

    double per = 0, area = 0;

    if (rectangle(a, b, &per, &area) != 0)
    {
        fprintf(stderr, "Ivalid rectriangle sides!\n");
        return EXIT_FAILURE;
    }
    else
    {
        printf("S: %.2lf\nP: %.2lf\n", area, per);
    }

    return EXIT_SUCCESS;
}

int rectangle(double a, double b, double *per, double *area)
{
    if (a <= 0 || b <= 0)
    {
        return -1;
    }

    *per = a + b;

    *area = a*b;

    return 0;
}