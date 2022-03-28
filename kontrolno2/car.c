#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define EPS 0.0001

typedef struct
{
    char model[20];
    uint8_t maxspeed;
    double price;
} Car;

int comparModelAscending(const void *, const void *);
int comparModelDescending(const void *, const void *);
int comparMaxspeedAscending(const void *, const void *);
int comparMaxspeedDescending(const void *, const void *);
int comparPriceAscending(const void *, const void *);
int comparPriceDescending(const void *, const void *);
int (*getComparator(int ))(const void *, const void *);
void randomModel(char *);
void randomSpeed(uint8_t *);
void randomPrice(double *);

int main()
{
    srand(time(NULL));
    Car cars[10];
    for (size_t i = 0; i < 10; i++)
    {
        randomModel(cars[i].model);
        randomSpeed(&cars[i].maxspeed);
        randomPrice(&cars[i].price);
    }

    unsigned compar;
    scanf("%u", &compar);

    qsort(cars, 10, sizeof(Car), getComparator(compar));

    for (size_t i = 0; i < 10; i++)
    {
        printf("%-15s ", cars[i].model);
        printf("%-10hu ", cars[i].maxspeed);
        printf("%.2lf\n", cars[i].price);
    }

    return EXIT_SUCCESS;
}

int comparModelAscending(const void *c1, const void *c2)
{
    Car car1 = *(Car *)c1;
    Car car2 = *(Car *)c2;
    return strcmp(car1.model, car2.model);
}

int comparModelDescending(const void *c1, const void *c2)
{
    Car car1 = *(Car *)c1;
    Car car2 = *(Car *)c2;
    return strcmp(car2.model, car1.model);
}

int comparMaxspeedAscending(const void *c1, const void *c2)
{
    Car car1 = *(Car *)c1;
    Car car2 = *(Car *)c2;
    return car1.maxspeed - car2.maxspeed;
}

int comparMaxspeedDescending(const void *c1, const void *c2)
{
    Car car1 = *(Car *)c1;
    Car car2 = *(Car *)c2;
    return car2.maxspeed - car1.maxspeed;
}

int comparPriceAscending(const void *c1, const void *c2)
{
    Car car1 = *(Car *)c1;
    Car car2 = *(Car *)c2;
    if (fabs(car1.price - car2.price) <= EPS)
    {
        return 0;
    }
    else if (car2.price < car1.price)
    {
        return 1;
    }
    return -1;
}

int comparPriceDescending(const void *c1, const void *c2)
{
    Car car1 = *(Car *)c1;
    Car car2 = *(Car *)c2;
    if (fabs(car1.price - car2.price) <= EPS)
    {
        return 0;
    }
    else if (car1.price < car2.price)
    {
        return 1;
    }
    return -1;
}

int (*getComparator(int n))(const void *, const void *)
{

    switch (n)
    {
    case 1:
        return comparModelAscending;
    case 2:
        return comparModelDescending;
    case 3:
        return comparMaxspeedAscending;
    case 4:
        return comparMaxspeedDescending;
    case 5:
        return comparPriceAscending;
    case 6:
        return comparPriceDescending;
    default:
        return NULL;
    }
}

void randomModel(char *str)
{
    for (size_t i = (rand() % 7) + 4, j = 0; j < i; j++)
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

void randomSpeed(uint8_t *speed)
{
    *speed = (rand() % 201) + 100;
}

void randomPrice(double *price)
{
    *price = (double)rand()/(RAND_MAX/(100000-1000))+1000;
}