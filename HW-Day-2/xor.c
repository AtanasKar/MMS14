#include <stdio.h>
#include <stdlib.h>

//gcc xor.c -o xor
//./xor < numbers.txt

unsigned xor (unsigned, unsigned);

int main()
{
    unsigned num1, num2, num3;
    scanf("%u %u %u", &num1, &num2, &num3);

    if (num1 > 1 || num2 > 1 || num3 > 1)
    {
        fprintf(stderr, "Invalid input!\n");
        return EXIT_FAILURE;
    }

    printf("%u\n", xor(xor(num1, num2), num3));

    return EXIT_SUCCESS;
}

unsigned xor (unsigned num1, unsigned num2) {
    return (!num1 && num2) || (!num2 && num1);
}