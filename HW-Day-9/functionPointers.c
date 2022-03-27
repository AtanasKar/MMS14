#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swapg(void *, void *, size_t);
void bubbleSort(void *, size_t, size_t, int (*)(const void *, const void *));
void (*getSorting(char *))(void *, size_t, size_t, int (*)(const void *, const void *));
void printArr(int *, size_t);
int compar(const void *, const void *);

int main()
{
    int arr[] = {1100, 2, 3, 4, 5, 6, 7, 23, 41, 52, 234, 234, 23416, 567};

    void (*fp[2])(void *, size_t, size_t, int (*)(const void *, const void *));
    fp[0] = getSorting("qsort");
    fp[1] = getSorting("bubbleSort");

    fp[0](arr, 14, sizeof(int), compar);

    printArr(arr, 14);

    return EXIT_SUCCESS;
}

void bubbleSort(void *arr, size_t length, size_t size, int (*compar)(const void *, const void *))
{

    for (size_t i = 0; i < length - 1; i++)
    {
        for (size_t j = 0; j < (length - i - 1) * size; j += size)
        {
            if (compar(arr + j, arr + j + size) < 0)
            {
                swapg(arr + j, arr + j + size, size);
            }
        }
    }
}

int compar(const void *lhs, const void *rhs)
{
    return *(int *)lhs - *(int *)rhs;
}

void swapg(void *lhs, void *rhs, size_t size)
{
    void *temp = malloc(size);
    memcpy(temp, lhs, size);
    memcpy(lhs, rhs, size);
    memcpy(rhs, temp, size);
    free(temp);
}

void (*getSorting(char *fname))(void *, size_t, size_t, int (*)(const void *, const void *))
{
    if (strcmp(fname, "qsort") == 0)
    {
        return qsort;
    }
    else if (strcmp(fname, "bubbleSort") == 0)
    {
        return bubbleSort;
    }
    return NULL;
}

void printArr(int *arr, size_t cnt)
{
    for (size_t i = 0; i < cnt; i++)
    {
        printf("%d ", arr[i]);
    }
    putchar('\n');
}