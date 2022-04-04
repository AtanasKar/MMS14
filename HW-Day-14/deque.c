#include <stdio.h>
#include <stdlib.h>

typedef struct deque
{
    int data;
    struct deque *next;
    struct deque *prev;
} deque_t;

void addAtBegin(int data, deque_t **deq)
{
    deque_t *list = malloc(sizeof(deque_t));
    list->data = data;
    list->next = *deq;
    list->prev = NULL;
    if ((*deq) != NULL)
    {
        (*deq)->prev = list;
    }
    (*deq) = list;
}

void addAtEnd(int data, deque_t **deq)
{
    deque_t *list = malloc(sizeof(deque_t));
    list->data = data;
    list->next = NULL;

    deque_t *temp = *deq;
    if (*deq == NULL)
    {
        list->prev = NULL;
        *deq = list;
        return;
    }

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = list;
    list->prev = temp;
}

void popBegin(deque_t **deq)
{
    deque_t *curr = *deq;
    (*deq) = curr->next;
    (*deq)->prev = NULL;
    free(curr);
}

void popEnd(deque_t **deq)
{
    deque_t *curr = *deq;
    while (curr->next)
    {
        curr = curr->next;
    }
    curr->prev->next = NULL;
    free(curr);
}

void printDeq(deque_t *deq)
{
    deque_t *curr = deq;
    while (curr != NULL)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    putchar('\n');
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};

    deque_t *deq = NULL;

    for (size_t i = 0; i < 5; i++)
    {
        addAtEnd(arr[i], &deq);
    }

    popBegin(&deq);
    popEnd(&deq);
    printDeq(deq);

    return EXIT_SUCCESS;
}