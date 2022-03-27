#include <stdio.h>
#include <stdlib.h>

unsigned sumArrayDigits(const int *arr, size_t n);

int main()
{
    int arr[] = {12, 34, 5, 70};

    printf("Sum: %u\n", sumArrayDigits(arr, 4));

    return EXIT_SUCCESS;
}

unsigned sumArrayDigits(const int *arr, size_t n)
{
    unsigned sum = 0;

    for (size_t i = 0; i < n; i++)
    {
        int temp=arr[i];
        while (temp)
        {
            sum+=temp%10;
            temp/=10;
        }
    }

    return sum;
}