#include <stdio.h>
#include <stdlib.h>

int binarySearch(int *, size_t, const int);

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 23, 41, 52, 234, 234, 23416, 567};

    int index = binarySearch(arr, 14, 567);

    if (index != -1)
    {
        printf("Index: %d\n", index);
    }
    else
    {
        fprintf(stderr, "Element not found!\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

int binarySearch(int *array, size_t n, const int key)
{
    unsigned low = 0;
    unsigned high = n;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (key == array[mid])
        {
            return mid;
        }
        else if (key > array[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}