#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define ARRAY_SIZE 500

void printArray(int ***, int);

int main()
{
    setlocale(LC_ALL,"");

    int **arrays[ARRAY_SIZE];
    int counter = 0;
    time_t start = 0, end = 0;
    double seconds = 0;

    start = clock();
    for(int i = 0; i < ARRAY_SIZE; i++) {
        arrays[i] = (int **)calloc(sizeof(int *), ARRAY_SIZE);
        for(int j = 0; j < ARRAY_SIZE; j++) {
            arrays[i][j] = (int *)calloc(sizeof(int), ARRAY_SIZE);
            for(int k = 0; k < ARRAY_SIZE; k++) {
                arrays[i][j][k] = counter++;
            }
        }
    }
    end = clock();
    seconds = ((end - start) / (double)CLOCKS_PER_SEC);
    printf("Create and populate arrays:\t%'ld Cycles\t%0.2lf Seconds\n", (end - start), seconds);
    // printArray(arrays, ARRAY_SIZE);
    
    start = clock();
    for(int i = 0; i < ARRAY_SIZE; i++)
    {
        arrays[i][0][0]++;
        for(int j = 0; j < ARRAY_SIZE; j++) {
            arrays[i][j][0]++;
            for(int k = 0; k < ARRAY_SIZE; k++) {
                arrays[i][j][k]++;
            }
        }
    }
    end = clock();
    seconds = ((end - start) / (double)CLOCKS_PER_SEC);
    printf("Processing X-axis first:\t%'ld Cycles\t%0.2lf Seconds\n", (end - start), seconds);

    start = clock();    
    for(int i = 0; i < ARRAY_SIZE; i++)
    {
        arrays[0][i][0]++;
        for(int j = 0; j < ARRAY_SIZE; j++) {
            arrays[j][i][0]++;
            for(int k = 0; k < ARRAY_SIZE; k++) {
                arrays[j][i][k]++;
            }
        }
    }
    end = clock();
    seconds = ((end - start) / (double)CLOCKS_PER_SEC);
    printf("Processing Y-axis first:\t%'ld Cycles\t%0.2lf Seconds\n", (end - start), seconds);
    
    
    start = clock();    
    for(int i = 0; i < ARRAY_SIZE; i++)
    {
        arrays[0][0][i]++;
        for(int j = 0; j < ARRAY_SIZE; j++) {
            arrays[j][0][i]++;
            for(int k = 0; k < ARRAY_SIZE; k++) {
                arrays[j][k][i]++;
            }
        }
    }
    end = clock();
    seconds = ((end - start) / (double)CLOCKS_PER_SEC);
    printf("Processing Z-axis first:\t%'ld Cycles\t%0.2lf Seconds\n", (end - start), seconds);

    start = clock();    
    for(int i = 0; i < ARRAY_SIZE; i++)
    {
        arrays[0][0][i]++;
        for(int j = 0; j < ARRAY_SIZE; j++) {
            arrays[0][j][i]++;
            for(int k = 0; k < ARRAY_SIZE; k++) {
                arrays[k][j][i]++;
            }
        }
    }
    end = clock();
    seconds = ((end - start) / (double)CLOCKS_PER_SEC);
    printf("Worst-case scenario:\t\t%'ld Cycles\t%0.2lf Seconds\n", (end - start), seconds);
}

void printArray(int ***array, int sizes)
{
    for(int i = 0; i < sizes; i++) {
        for(int j = 0; j < sizes; j++) {
            for(int k = 0; k < sizes; k++) {
                printf("%d\t", array[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
}