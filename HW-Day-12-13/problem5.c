#include <stdio.h>

#define MAX_SIZE 20

int arr[MAX_SIZE];
int top = 0;
int bottom = 0;

int isEmpty()
{
    return top;
}

int isFull()
{
    if (top >= MAX_SIZE)
    {
        return 0;
    }
    return 1;
}

void Push(int nNewValue)
{
    arr[top] = nNewValue;
    top++;
}

int Pop()
{
    for (size_t i = 0; i < top - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    top--;
}

int main()
{
   
    return 0;
}