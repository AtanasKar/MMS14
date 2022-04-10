#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <semaphore.h>

#define EPS 0.001
#define COUNT 10

enum description
{
    Food,
    NotFood
};

// produkt
typedef struct
{
    enum description descr;
    unsigned barcode;
    double price;
} Stock;

// sklad
typedef struct node
{
    Stock stock;
    struct node *next;
} LinkedList;

LinkedList *create_ll(Stock);
void listFree(LinkedList **);
void push(Stock, LinkedList **);
void printList(LinkedList *);
double randomPrice();
unsigned randomBarcode();
unsigned randomDescription();
void *consumer(void *);
void *producer(void *);
void deleteNth(LinkedList **, size_t);
void printStock(Stock *);

LinkedList *list = NULL;
int listDataCnt = 0;

sem_t freePos;
sem_t busyPos;
pthread_mutex_t mux;

int main(int argc, char **argv)
{
    srand(time(NULL));
    sem_init(&freePos, 0, COUNT);
    sem_init(&busyPos, 0, 0);
    pthread_mutex_init(&mux, NULL);
    pthread_t th[COUNT];

    if ((argc - 1) % 3 == 0 && argc != 1)
    {
        for (size_t i = 1; i < argc; i += 3)
        {
            Stock stock;
            stock.barcode = atoi(argv[i]);
            stock.descr = atoi(argv[i + 1]);
            stock.price = strtod(argv[i + 2], NULL);
            push(stock, &list);
        }
    }
    else
    {
        for (int i = 0; i < COUNT; i++)
        {

            if (i == 0)
            {

                if (pthread_create(th + i, NULL, producer(NULL), NULL) != 0)
                {
                    perror("create");
                    return EXIT_FAILURE;
                }
            }
            else
            {
                if (pthread_create(th + i, NULL, consumer, NULL) != 0)
                {
                    perror("create");
                    return EXIT_FAILURE;
                }
            }
        }

        for (int i = 0; i < COUNT; i++)
        {
            if (pthread_join(th[i], NULL) != 0)
            {
                perror("join");
                return EXIT_FAILURE;
            }
        }
        pthread_mutex_destroy(&mux);
        sem_destroy(&freePos);
        sem_destroy(&busyPos);
    }

    printList(list);

    return EXIT_SUCCESS;
}

void deleteNth(LinkedList **list, size_t n)
{
    if (*list == NULL)
    {
        return;
    }
    if (n == 0)
    {
        LinkedList *temp = *list;
        *list = (*list)->next;
        free(temp);
        return;
    }
    LinkedList *current = *list;
    LinkedList *prev = current;
    while (current && n--)
    {
        prev = current;
        current = current->next;
    }
    prev->next = current->next;
    free(current);
}

void *producer(void *args)
{
    while (1)
    {
        sleep(1);
        sem_wait(&freePos);
        pthread_mutex_lock(&mux);
        Stock stock;
        stock.barcode = randomBarcode();
        stock.descr = randomDescription();
        stock.price = randomPrice();
        push(stock, &list);
        listDataCnt++;
        pthread_mutex_unlock(&mux);
        sem_post(&busyPos);
        printf("Stock is added: ");
        printStock(&stock);
    }
}

void printStock(Stock *stock)
{
    printf("%u ", stock->barcode);
    printf("%d ", stock->descr);
    printf("%.2lf\n", stock->price);
}

void *consumer(void *args)
{
    while (1)
    {
        sleep(1);
        sem_wait(&busyPos);
        pthread_mutex_lock(&mux);
        deleteNth(&list, rand() % listDataCnt);
        listDataCnt--;
        pthread_mutex_unlock(&mux);
        sem_post(&freePos);
        printf("Stock is removed: ");
    }
}

unsigned randomDescription()
{
    return rand() % 2;
}

unsigned randomBarcode()
{
    return rand() % 10000000;
}

double randomPrice()
{
    return 0.1 + (rand() / 1000);
}

LinkedList *create_ll(Stock st)
{
    LinkedList *list = malloc(sizeof(LinkedList));
    list->stock = st;
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

void push(Stock st, LinkedList **ll)
{
    LinkedList *temp = create_ll(st);
    temp->stock = st;
    temp->next = *ll;
    *ll = temp;
}

void printList(LinkedList *ll)
{
    LinkedList *curr = ll;
    while (curr)
    {
        printf("%u ", curr->stock.barcode);
        printf("%d ", curr->stock.descr);
        printf("%.2lf\n", curr->stock.price);
        curr = curr->next;
    }
}