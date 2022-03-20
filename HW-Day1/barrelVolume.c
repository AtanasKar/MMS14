#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#ifndef M_PI
#   define M_PI 3.14159265358979323846
#endif

int main()
{
    double R, H;
    scanf("%lf %lf", &R, &H);

    if (R <= 0 || H <= 0)
    {
        fprintf(stderr, "Invalid arguments!\n");
        return EXIT_FAILURE;
    }

    double volume = 0;

    volume = R * R * H * M_PI;

    printf("Volume = %.2lf\n", volume);

    return EXIT_SUCCESS;
}