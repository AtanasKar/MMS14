#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

void *writeInFile(FILE *fp, char *row, int *rowNum, int *rowData, unsigned dataCount)
{
    fwrite(row, strlen((char *)row), 1, fp);
    fwrite(rowNum, sizeof(int), 1, fp);
    fwrite(rowData, sizeof(int), dataCount, fp);
    fputc('\n', fp);

    return NULL;
}

int main()
{
    unsigned N, M;
    scanf("%u %u", &N, &M);

    int **matrix = malloc(sizeof(int) * N);
    for (size_t i = 0; i < N; i++)
    {
        matrix[i] = malloc(sizeof(int) * M);
    }

    pthread_t *ths = malloc(sizeof(pthread_t) * N);
    if (ths == NULL)
    {
        perror("malloc");
        return EXIT_FAILURE;
    }

    char **rowBuff = malloc(sizeof(char) * N);
    for (size_t i = 0; i < N; i++)
    {
        rowBuff[i] = malloc(sizeof(char) * 20);
    }

    int *rowNum = malloc(sizeof(int) * N);
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < M + 2; j++)
        {
            if (j == 0)
            {
                scanf("%s", rowBuff[i]);
            }
            else if (j == 1)
            {
                scanf("%d", &rowNum[i]);
            }
            else
            {
                scanf("%d", &matrix[i][j - 2]);
            }
        }
    }
    char fileNameBuff[20];
    scanf("%s", fileNameBuff);

    FILE *fp = fopen(fileNameBuff, "w");
    if (fp == NULL)
    {
        perror("fopen");
        exit(-1);
    }

    for (size_t i = 0; i < N; i++)
    {

        if (pthread_create(&ths[i], NULL, writeInFile(fp, rowBuff[i], rowNum, matrix[i], M), NULL) != 0)
        {
            perror("pthread create");
            return EXIT_FAILURE;
        }

        if (pthread_join(ths[i], NULL) != 0)
        {
            perror("pthread join");
            return EXIT_FAILURE;
        }
    }

    fclose(fp);

    for (size_t i = 0; i < N; i++)
    {
        free(matrix[i]);
    }
    free(matrix);

    return EXIT_SUCCESS;
}