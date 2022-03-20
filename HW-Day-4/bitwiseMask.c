#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void setAtt(uint32_t *attList, unsigned pos)
{
    *attList |= (1 << pos);
}

void clearAtt(uint32_t *attList, unsigned pos)
{
    *attList &= ~(1 << pos);
}

unsigned checkAtt(uint32_t attList, unsigned pos)
{
    return !!(attList & (1 << pos));
}

void changeAtt(uint32_t *attList, unsigned pos)
{
    *attList ^= (1 << pos);
}

unsigned getPosition()
{
    unsigned pos;

    printf("Position: ");
    scanf("%u", &pos);

    return pos;
}

int main()
{
    uint32_t attendance = 0;
    unsigned option, position;

    do
    {
        printf("1. Set attendance\n");
        printf("2. Clear attendance\n");
        printf("3. Attendance info\n");
        printf("4. Change attendance\n");
        printf("5. Not on the list (by numbers)\n");
        printf("6. On the list (by numbers)\n");
        printf("7. Exit\n");
        scanf("%u", &option);

        switch (option)
        {
        case 1:
            position = getPosition();
            if (position > 31)
            {
                fprintf(stderr, "Invalid position\n");
                return EXIT_FAILURE;
            }
            setAtt(&attendance, position);
            break;
        case 2:
            position = getPosition();
            if (position > 31)
            {
                fprintf(stderr, "Invalid position\n");
                return EXIT_FAILURE;
            }
            clearAtt(&attendance, position);
            break;
        case 3:
            for (int i = sizeof(uint32_t) * 8 - 1; i >= 0; i--)
            {
                printf("%d", checkAtt(attendance, i));
            }
            printf("\n");
            break;
        case 4:
            position = getPosition();
            if (position > 31)
            {
                fprintf(stderr, "Invalid position\n");
                return EXIT_FAILURE;
            }
            changeAtt(&attendance, position);
            break;
        case 5:
            for (int i = 0; i < sizeof(uint32_t) * 8; i++)
            {
                if (!(checkAtt(attendance, i)))
                {
                    printf("%d ", i);
                }
            }
            printf("\n");
            break;
        case 6:
            for (int i = 0; i < sizeof(uint32_t) * 8; i++)
            {
                if (checkAtt(attendance, i))
                {
                    printf("%d ", i);
                }
            }
            printf("\n");
            break;
        case 7:
            printf("Bye!\n");
            return EXIT_SUCCESS;
        default:
            fprintf(stderr, "Invalid command!\n");
            return EXIT_FAILURE;
        }
    } while (1);

    return EXIT_SUCCESS;
}