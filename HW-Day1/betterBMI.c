#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    double mass, height;
    double bodyMassIndex = 0;

    scanf("%lf %lf", &mass, &height);

    if (mass <= 0 || height <= 0)
    {
        fprintf(stderr, "Invalid arguments\n");
        return EXIT_FAILURE;
    }

    bodyMassIndex = 1.3 * mass / pow(height, 2.5);

    printf("BMInew = %.2lf\n", bodyMassIndex);

    return EXIT_SUCCESS;
}