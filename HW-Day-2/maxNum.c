#include <stdio.h>
#include <stdlib.h>

//gcc maxNum.c -o maxNum
//./maxNum < numbers.txt

int main()
{
    double num1, num2, num3;
    scanf("%lf %lf %lf", &num1, &num2, &num3);

    double max = num1;
    if (num1 < num2)
    {
        max = num2;
    }
    else if (max < num3)
    {
        max = num3;
    }
    printf("Max number: %lf\n", max);

    return EXIT_SUCCESS;
}