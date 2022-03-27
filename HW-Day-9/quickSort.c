#include <stdio.h>
#include <stdlib.h>

void swapInt(int *, int *);
void quickSort(int *, int, int);
void printArr(int *, size_t);

int main()
{
    int arr[] = {1100, 2, 3, 4, 5, 6, 7, 23, 41, 52, 234, 234, 23416, 567};

    quickSort(arr, 0, 14 - 1);

    printArr(arr, 14);

    return EXIT_SUCCESS;
}

void swapInt(int *lhs, int *rhs)
{
    int temp = *lhs;
    *lhs = *rhs;
    *rhs = temp;
}

void quickSort(int *arr, int first, int last)
{
    int i, j, pivot, temp;

    if (first < last)
    {
        pivot = first;
        i = first;
        j = last;

        while (i < j)
        {
            while (arr[i] <= arr[pivot] && i < last)
            {
                i++;
            }
            while (arr[j] > arr[pivot])
            {
                j--;
            }
            if (i < j)
            {
                swapInt(&arr[i], &arr[j]);
            }
        }
        swapInt(&arr[pivot], &arr[j]);
        quickSort(arr, first, j - 1);
        quickSort(arr, j + 1, last);
    }
}

void printArr(int *arr, size_t cnt)
{
    for (size_t i = 0; i < cnt; i++)
    {
        printf("%d ", arr[i]);
    }
    putchar('\n');
}