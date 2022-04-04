#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define COUNT 10

typedef struct
{
    double x;
    double y;
} point_t;

typedef struct
{
    point_t A;
    point_t B;
} rectangle_t;

typedef struct node
{
    rectangle_t rectangle;
    struct node *next;
} node_t;

void randCoords(point_t *point)
{
    point->x = rand() % 20;
    if (point->x > 10)
    {
        point->x /= 10 * (-1);
    }
    point->y = rand() % 20;
    if (point->y > 10)
    {
        point->y /= 10 * (-1);
    }
}

double areaOfRect(rectangle_t rect)
{
    double width = 0;
    double high = 0;
    if (rect.A.x > rect.B.x)
    {
        width = rect.A.x - rect.B.x;
    }
    else
    {
        width = rect.B.x - rect.A.x;
    }
    if (rect.A.y > rect.B.y)
    {
        high = rect.A.y - rect.B.y;
    }
    else
    {
        high = rect.B.y - rect.A.y;
    }
    return width * high;
}

double areaRects(node_t *list)
{
    node_t *current = list;
    node_t *prev = current;

    double areaSum = 0;
    while (current)
    {
        areaSum += areaOfRect(current->rectangle);
        prev = current;
        current = current->next;
    }
    return areaSum;
}

node_t *createNode_t(rectangle_t rect)
{
    node_t *temp = malloc(sizeof(node_t));
    temp->rectangle = rect;
    temp->next = NULL;
    return temp;
}

void listFree(node_t **list)
{
    node_t *current = *list, *prev;
    while (current)
    {
        prev = current;
        current = current->next;
        free(prev);
    }
    *list = NULL;
}

void push(node_t **list, rectangle_t rect)
{
    node_t *temp = createNode_t(rect);
    temp->rectangle = rect;
    temp->next = *list;
    *list = temp;
}

void filterRects(node_t **list, double min, double max)
{
    if (*list == NULL)
    {
        return;
    }
    node_t *current = *list;
    node_t *prev = current;

    double area = 0;
    while (current)
    {
        area = areaOfRect(current->rectangle);
        if (area > min && area < max)
        {
            node_t *temp = *list;
            *list = (*list)->next;
            free(temp);
        }
        
        prev = current;
        current = current->next;
    }
}

void print_list(node_t* list){
    node_t* current=list;
    while (current)
    {
        printf("Ax: %-7.2lf ",current->rectangle.A.x);
        printf("Ay: %-7.2lf ",current->rectangle.A.y);
        printf("Bx: %-7.2lf ",current->rectangle.B.x);
        printf("By: %.2lf ",current->rectangle.B.y);
        putchar('\n');
        current=current->next;
    }
    
}

int main()
{
    srand(time(NULL));

    rectangle_t rect;
    randCoords(&rect.A);
    randCoords(&rect.B);

    node_t *list = createNode_t(rect);

    for (size_t i = 1; i < COUNT; i++)
    {
        randCoords(&rect.A);
        randCoords(&rect.B);
        push(&list, rect);
    }
    print_list(list);
    putchar('\n');

    filterRects(&list,20,100);

    print_list(list);
    return 0;
}