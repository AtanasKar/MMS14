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

typedef struct
{
    Book book;
    struct LinkedList *next;
} LinkedList;


void randomName(char *);
void randomPages(unsigned *);
void randomPrice(double *);
void swapg(void *, void *, size_t);
int comparPrice(const void *, const void *);
int comparPages(const void *, const void *);
int comparTitles(const void *, const void *);
int comparAuthors(const void *, const void *);
void bubbleSort(void *, size_t, size_t, int (*)(const void *, const void *));
void printBooks(Book *, size_t);

LinkedList* create_ll(Book b){
    LinkedList* list= malloc(sizeof(LinkedList));
    list->book=b;
    list->next=NULL;
    return list;
}

void push(Book b,LinkedList** ll){
    LinkedList* temp = create_ll(b);
    temp->book=b;
    temp->next=NULL;
    *ll=temp;
}

void printList(LinkedList* ll){
    LinkedList* curr=ll;
    while (curr)
    {
        printf("%-25s",curr->book.title);
        printf("%-25s",curr->book.author);
        printf("%-10d",curr->book.pages);
        printf("%lf",curr->book.price);
        curr=curr->next;
    }
    putchar('\n');
}

// LinkedList* sortedMerge(LinkedList* listA,LinkedList* listB, int(*cmp)(const void*,const void*)){
//     LinkedList* sorted =NULL;
//     if(listA==NULL){
//         return listB;
//     }
//     if(listB==NULL){
//         return listA;
//     }
//     if(cmp(&listA->book,&listB->book)>0){
//         sorted=listA;
//         sorted->next=sortedMerge(listA->next,listB,cmp);
//     }else{
//         sorted=listB;
//         sorted->next=sortedMerge(listA,listB->next,cmp);
//     }
//     return sorted;
// }

// void frontBackSplit(LinkedList* ll,LinkedList** front,LinkedList** back){
//     LinkedList* slow=ll;
//     LinkedList* fast=ll->next;
//     while (fast!=NULL)
//     {
//         fast=fast->next;
//         if(fast!=NULL){
//             slow=slow->next;
//             fast=fast->next;
//         }
//         *front=ll;
//         *back=slow->next;
//         slow->next=NULL;
//     }
    
// }

// void mergeSort(LinkedList** ll,int(*cmp)(const void*,const void*)){
//     if(*ll==NULL||(*ll)->next==NULL){
//         return;
//     }
//     LinkedList *front=NULL,*back=NULL;
//     frontBackSplit(*ll,&front,&back);
//     mergeSort(&front,cmp);
//     mergeSort(&back,cmp);
//     *ll=sortedMerge(front,back,cmp);
// }

int main()
{
    srand(time(NULL));

    LinkedList* list=NULL;

    for (size_t i = 0; i < COUNT; i++)
    {
        Book book;
        randomName(book.title);
        randomName(book.author);
        randomPages(&book.pages);
        randomPrice(&book.price);
        push(book,&list);
    }

    
    printList(list);
    

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

void swapg(void *lhs, void *rhs, size_t size)
{
    void *temp = malloc(size);
    memcpy(temp, lhs, size);
    memcpy(lhs, rhs, size);
    memcpy(rhs, temp, size);
    free(temp);
}

int comparPrice(const void *b1, const void *b2)
{
    Book book1 = *(Book *)b1;
    Book book2 = *(Book *)b2;
    if (fabs(book2.price - book1.price) < EPS)
    {
        return 0;
    }
    else if (book2.price < book1.price)
    {
        return -1;
    }
    return 1;
}

int comparPages(const void *b1, const void *b2)
{
    Book book1 = *(Book *)b1;
    Book book2 = *(Book *)b2;
    return book2.pages - book1.pages;
}

int comparTitles(const void *b1, const void *b2)
{
    Book book1 = *(Book *)b1;
    Book book2 = *(Book *)b2;
    return strcmp(book2.title, book1.title);
}

int comparAuthors(const void *b1, const void *b2)
{
    Book book1 = *(Book *)b1;
    Book book2 = *(Book *)b2;
    return strcmp(book1.author, book2.author);
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