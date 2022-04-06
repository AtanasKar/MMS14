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

int comparTitles(Book, Book);
LinkedList *create_ll(Book);
void listFree(LinkedList **);
void push(Book, LinkedList **);
void printList(LinkedList *);
LinkedList *sortedMerge(LinkedList *, LinkedList *, int (*)(Book, Book));
void frontBackSplit(LinkedList *, LinkedList **, LinkedList **);
void mergeSort(LinkedList **, int (*)(Book, Book));

int main(int argc, char **argv)
{
    srand(time(NULL));

    LinkedList *list = NULL;

    FILE *fp1 = fopen(argv[1], "rb");
    if (NULL == fp1)
    {
        perror("Error info");
        return EXIT_FAILURE;
    }

    for (size_t i = 0; i < COUNT; i++)
    {
        Book book;
        fread(&book, sizeof(Book), 1, fp1);
        push(book, &list);
    }

    fclose(fp1);

    mergeSort(&list, comparTitles);

    FILE *fp2 = fopen(argv[2], "wb");
    if (NULL == fp2)
    {
        perror("Error info");
        return EXIT_FAILURE;
    }

    for (size_t i = 0; i < COUNT; i++)
    {
        fwrite(&list->book, sizeof(Book), 1, fp2);
        list=list->next;
    }

    fclose(fp2);

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

int comparTitles(Book b1, Book b2)
{
    Book book1 = b1;
    Book book2 = b2;
    return strcmp(book2.title, book1.title);
}