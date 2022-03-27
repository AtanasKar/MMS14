#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int secondMax(const int *arr, size_t n, int *secondMax);

int main()
{
    int sm;
    int arr[] = {12, 34, 5, 70, 46};

    switch (secondMax(arr, 5, &sm))
    {
    case -1:
        fprintf(stderr, "Not enough elements!\n");
        return EXIT_FAILURE;
    case 1:
        fprintf(stderr, "All elements are the same!\n");
        return EXIT_FAILURE;
    }

    printf("%d\n", sm);

    return EXIT_SUCCESS;
}

int secondMax(const int *arr, size_t n, int *secondMax)
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

    *secondMax = secMax;
    return 0;
}