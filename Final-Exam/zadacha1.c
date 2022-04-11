#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdint.h>
#include <inttypes.h>
#include <limits.h>

#define EPS 0.001
#define ITEMS_COUNT 3

typedef struct
{
    uint16_t number;
    char description[250];
    double weigth;
    double price;
} Item;

typedef struct node
{
    Item item;
    struct node *next;
} LinkedList;

void randomDescription(char *);
uint16_t randomNumber();
double randomWeigth();
double randomPrice();
LinkedList *create_ll(Item);
void listFree(LinkedList **);
void push(Item, LinkedList **);
void printList(LinkedList *);
double totalItemsWeight(LinkedList *);
LinkedList *minPriceItem(LinkedList *);

int main()
{
    srand(time(NULL));

    LinkedList *list = NULL;

    for (size_t i = 0; i < ITEMS_COUNT; i++)
    {
        Item item;
        item.number = randomNumber();
        randomDescription(item.description);
        item.weigth = randomWeigth();
        item.price = randomPrice();
        push(item, &list);
    }

    printList(list);

    putchar('\n');

    printf("total weight: %.2lf\n", totalItemsWeight(list));

    printf("min price: %.2lf\n", minPriceItem(list)->item.price);

    listFree(&list);

    return EXIT_SUCCESS;
}

LinkedList *create_ll(Item itm)
{
    LinkedList *list = malloc(sizeof(LinkedList));
    list->item = itm;
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

void push(Item itm, LinkedList **ll)
{
    LinkedList *temp = create_ll(itm);
    temp->item = itm;
    temp->next = *ll;
    *ll = temp;
}

void printList(LinkedList *ll)
{
    LinkedList *curr = ll;
    while (curr)
    {
        printf("%-10u", curr->item.number);
        printf("%-25s", curr->item.description);
        printf("%-10.2lf", curr->item.weigth);
        printf("%.2lf\n", curr->item.price);
        curr = curr->next;
    }
}

void randomDescription(char *str)
{
    // zadal sum go da generira do 25 simvola za naglednost
    // ako imam vreme shte go doopravqm da generira dumi :)
    for (size_t i = rand() % 25, j = 0; j < i; j++)
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

uint16_t randomNumber()
{
    return rand() % SHRT_MAX;
}

double randomPrice()
{
    double range = (1500 - 1);
    double div = RAND_MAX / range;
    return 1 + (rand() / div);
}

double randomWeigth()
{
    double range = (100 - 0.1);
    double div = RAND_MAX / range;
    return 0.1 + (rand() / div);
}

double totalItemsWeight(LinkedList *items)
{
    LinkedList *curr = items;
    double totalWeight = 0;
    while (curr)
    {
        totalWeight += curr->item.weigth;
        curr = curr->next;
    }
    return totalWeight;
}

LinkedList *minPriceItem(LinkedList *items)
{
    LinkedList *curr = items;
    double minPrice = curr->item.price;
    if (curr->next != NULL)
    {
        curr = curr->next;
    }
    while (curr)
    {
        if (curr->item.price < minPrice)
        {
            minPrice = curr->item.price;
        }
        curr = curr->next;
    }
    curr = items;
    while (curr)
    {
        if (curr->item.price == minPrice)
        {
            return curr;
        }
        curr = curr->next;
    }
    return NULL;
}