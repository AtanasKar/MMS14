#include <stdio.h>
#include <stdlib.h>
#define PI 3.141592653589793

int cylinder(double, double, double *, double *);

int main()
{
    double r, h, V = 0, S = 0;

    while (scanf("%lf %lf", &r, &h) != EOF)
    {
        if (cylinder(r, h, &V, &S) != 0)
        {
            fprintf(stderr, "Invalid arguments!\n");
            return EXIT_FAILURE;
        }

        printf("V = %.2lf, S = %.2lf\n", V, S);
    }

    return EXIT_SUCCESS;
}

int cylinder(double r, double h, double *V, double *S)
{
    if (r <= 0 || h <= 0)
    {
        return -1;
    }

    *S = 2 * PI * r * h;
    *V = PI * r * r * h;

    return 0;
}