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

void randomName(char *);
void randomPages(unsigned *);
void randomPrice(double *);
int comparPrice(const void *, const void *);
void printBooks(Book *, size_t);
void *linearSearch(const void *, void *, size_t, size_t, int (*)(const void *, const void *));

int main()
{
    srand(time(NULL));

    Book books[COUNT];

    for (size_t i = 0; i < COUNT; i++)
    {
        randomName(books[i].title);
        randomName(books[i].author);
        randomPages(&books[i].pages);
        randomPrice(&books[i].price);
    }

    // books[7].price = 20.5;

    printBooks(books, COUNT);

    double key = 20.5;
    Book *item = linearSearch(&key, books, COUNT, sizeof(Book), comparPrice);
    if (item != NULL)
    {
        printf("\nFirst book that costs 20,50 lv is \"%s\".\n", item->title);
    }
    else
    {
        fprintf(stderr, "Item not found!\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
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
    *price = (rand() % 1000) / (double)(rand() % 1000) + 1;
}

int comparPrice(const void *b1, const void *b2)
{
    Book book2 = *(Book *)b2;
    if (fabs(book2.price - *(double *)b1) < EPS)
    {
        return 0;
    }
    else if (book2.price < *(double *)b1)
    {
        return -1;
    }
    return 1;
}

void printBooks(Book *books, size_t count)
{
    char *row1[] = {"Titles:", "Authors:", "Pages:", "Prices:"};
    printf("%-24s %-24s %-9s %s\n", row1[0], row1[1], row1[2], row1[3]);
    for (size_t i = 0; i < count; i++)
    {
        printf("%-25s", books[i].title);
        printf("%-25s", books[i].author);
        printf("%-10u", books[i].pages);
        printf("%lf\n", books[i].price);
    }
}

void *linearSearch(const void *key, void *base, size_t nitems, size_t size, int (*compar)(const void *, const void *))
{
    for (size_t i = 0; i < nitems * size; i += size)
    {
        if (compar(key, base + i) == 0)
        {
            return base + i;
        }
    }
    return NULL;
}