#include <stdio.h>

unsigned recursion(unsigned *arr, size_t length, size_t pos, size_t steps)
{
    if (pos < 0 || pos >= length)
    {
        return steps;
    }
    unsigned temp = arr[pos];
    unsigned evenOrOdd = 0;
    while (temp)
    {
        evenOrOdd += temp % 10;
        temp /= 10;
    }
    if (evenOrOdd % 2 == 0)
    {
        recursion(arr, length, pos + 3, steps + 1);
    }
    else
    {
        recursion(arr, length, pos - 2, steps + 1);
    }
}

int main()
{
    unsigned arr[] = {5, 23, 77, 123, 681, 9, 772,16};
    unsigned steps = recursion(arr, 8, 4, 0);
    printf("%u\n", steps);

    return 0;
}