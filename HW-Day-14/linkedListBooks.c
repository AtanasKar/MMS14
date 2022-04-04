#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdint.h>

#define EPS 0.001
#define COUNT 10

typedef struct
{
    char title[150];
    char author[100];
    unsigned pages;
    double price;
} Book;

typedef struct node
{
    Book book;
    struct node *next;
} LinkedList;

void randomName(char *);
void randomPages(unsigned *);
void randomPrice(double *);
int comparTitles(Book, Book);
LinkedList *create_ll(Book);
void listFree(LinkedList **);
void push(Book, LinkedList **);
void printList(LinkedList *);
LinkedList *sortedMerge(LinkedList *, LinkedList *, int (*)(Book, Book));
void frontBackSplit(LinkedList *, LinkedList **, LinkedList **);
void mergeSort(LinkedList **, int (*)(Book, Book));

int main()
{
    srand(time(NULL));

    LinkedList *list = NULL;

    for (size_t i = 0; i < COUNT; i++)
    {
        Book book;
        randomName(book.title);
        randomName(book.author);
        randomPages(&book.pages);
        randomPrice(&book.price);
        push(book, &list);
    }

    mergeSort(&list, comparTitles);

    printList(list);

    listFree(&list);

    return EXIT_SUCCESS;
}

LinkedList *create_ll(Book b)
{
    LinkedList *list = malloc(sizeof(LinkedList));
    list->book = b;
    list->next = NULL;
    return list;
}

void listFree(LinkedList **list)
{
    LinkedList *current = *list;
    LinkedList *prev;
    while (current)
    {
        prev = current;
        current = current->next;
        free(prev);
    }
    *list = NULL;
}

void push(Book b, LinkedList **ll)
{
    LinkedList *temp = create_ll(b);
    temp->book = b;
    temp->next = *ll;
    *ll = temp;
}

void printList(LinkedList *ll)
{
    LinkedList *curr = ll;
    while (curr)
    {
        printf("%-25s", curr->book.title);
        printf("%-25s", curr->book.author);
        printf("%-10d", curr->book.pages);
        printf("%.2lf\n", curr->book.price);
        curr = curr->next;
    }
}

LinkedList *sortedMerge(LinkedList *listA, LinkedList *listB, int (*cmp)(Book, Book))
{
    LinkedList *sorted = NULL;
    if (listA == NULL)
    {
        return listB;
    }
    if (listB == NULL)
    {
        return listA;
    }
    if (cmp(listA->book, listB->book) > 0)
    {
        sorted = listA;
        sorted->next = sortedMerge(listA->next, listB, cmp);
    }
    else
    {
        sorted = listB;
        sorted->next = sortedMerge(listA, listB->next, cmp);
    }
    return sorted;
}

void frontBackSplit(LinkedList *list, LinkedList **front, LinkedList **back)
{
    LinkedList *slow = list;
    LinkedList *fast = list->next;
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    *front = list;
    *back = slow->next;
    slow->next = NULL;
}

void mergeSort(LinkedList **list, int (*cmp)(Book, Book))
{
    if (*list == NULL || (*list)->next == NULL)
    {
        return;
    }
    LinkedList *front = NULL, *back = NULL;
    frontBackSplit(*list, &front, &back);
    mergeSort(&front, cmp);
    mergeSort(&back, cmp);
    *list = sortedMerge(front, back, cmp);
}

void randomName(char *str)
{
    for (size_t i = (rand() % 10) + 10, j = 0; j < i; j++)
    {
        if (j == 0)
        {
            str[j] = 'A' + (rand() % 26);
        }
        else
        {
            str[j] = 'a' + (rand() % 26);
        }

        if (j + 1 == i)
        {
            str[j + 1] = '\0';
        }
    }
}

void randomPages(unsigned *pgs)
{
    *pgs = (rand() % 1995) + 5;
}

void randomPrice(double *price)
{
    *price = 1 + ((double)rand() / RAND_MAX) * (1000 - 1);
}

int comparTitles(Book b1, Book b2)
{
    Book book1 = b1;
    Book book2 = b2;
    return strcmp(book2.title, book1.title);
}