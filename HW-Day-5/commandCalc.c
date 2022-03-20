#include <stdio.h>
#include <stdlib.h>

int main()
{
    double firstNum, secondNum, result = 0;
    char operator;

    if(scanf("%lf %c %lf", &firstNum, &operator, & secondNum)!=3){
        fprintf(stderr, "Invalid input\n");
        return EXIT_FAILURE;
    }

    switch (operator)
    {
    case '+':
        result = firstNum + secondNum;
        break;
    case '-':
        result = firstNum - secondNum;
        break;
    case '*':
        result = firstNum * secondNum;
        break;
    case '/':
        result = firstNum / secondNum;
        break;
    default:
        fprintf(stderr, "Invalid operator\n");
        return EXIT_FAILURE;
    }

    printf("%.2lf\n",result);

    return EXIT_SUCCESS;
}