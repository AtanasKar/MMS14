#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} node_t;

struct Node *head = NULL;

void push(node_t **list, int data)
{
    node_t *temp = malloc(sizeof(node_t));
    temp->data = data;
    if (head == NULL)
    {
        head = temp;
        head->next = head;
    }
    else
    {
        temp->next = head;
        head = temp;
    }
}

void print_list(node_t *list)
{
    node_t *current = head;

    while (current->next != current)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    putchar('\n');
}

int main()
{

    int arr[] = {1, 2, 3};
    node_t *list = NULL;
    for (size_t i = 0; i < 3; i++)
    {
        push(&list, arr[i]);
    }

    print_list(list);

    return 0;
}