#include <stdio.h>
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

    bodyMassIndex = mass / (height * height);

    printf("BMI = %.2lf \n", bodyMassIndex);

    return EXIT_SUCCESS;
}
