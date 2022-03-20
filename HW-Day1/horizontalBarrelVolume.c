#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    double R, H, L;
    scanf("%lf %lf %lf", &R, &L, &H);

    if (R <= 0 || H <= 0 || L <= 0)
    {
        fprintf(stderr, "Invalid arguments\n");
        return EXIT_FAILURE;
    }

    double area = 0;
    double volume = 0;

    area = (acos((R - H) / R)) * R * R - (R - H) * sqrt(2 * R * H - H * H);

    volume = area * L;

    printf("Volume = %.2lf\n", volume);

    return EXIT_SUCCESS;
}