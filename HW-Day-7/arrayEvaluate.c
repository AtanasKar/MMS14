#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void arrayEvaluate(int *arr, size_t n, int (*f)(int *, size_t));
int secondMax(int *arr, size_t n);
int sumArrayDigits(int *arr, size_t n);

int main()
{
    int arr[]={1,2,3};

    arrayEvaluate(arr,3,sumArrayDigits);
    arrayEvaluate(arr,3,secondMax);

    return EXIT_SUCCESS;
}

void arrayEvaluate(int *arr, size_t n, int (*f)(int *, size_t))
{
    printf("Value: %d\n",(*f)(arr, n));
}

int secondMax(int *arr, size_t n)
{
    if (n < 2)
    {
        return -1;
    }

    int max = INT_MIN;
    int secMax = INT_MIN;
    for (size_t i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            secMax = max;
            max = arr[i];
        }
        else if (secMax < arr[i] && arr[i] != max)
        {
            secMax = arr[i];
        }
    }

    if (secMax == INT_MIN)
    {
        return 1;
    }

    return secMax;
}

int sumArrayDigits(int *arr, size_t n)
{
    int sum = 0;

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