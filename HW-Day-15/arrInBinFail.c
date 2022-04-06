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

int main(int argc, char **argv)
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

    FILE *fp = fopen(argv[1], "wb");
    if (NULL == fp)
    {
        perror("Error info");
        return EXIT_FAILURE;
    }

    fwrite(books,sizeof(books),1,fp);

    printf("%ld\n",sizeof(books));
    printf("%ld\n",sizeof(Book));

    fclose(fp);

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
    *price = 1 + ((double)rand() / RAND_MAX) * (1000 - 1);
}

int comparTitles(Book b1, Book b2)
{
    Book book1 = b1;
    Book book2 = b2;
    return strcmp(book2.title, book1.title);
}