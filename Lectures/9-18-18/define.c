#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 10

int main()
{
    int *array = calloc(sizeof(int), ARRAY_SIZE);

    for(int i = 0; i < ARRAY_SIZE; i++)
    {
        //array[i] = i;
        *(array + i) = i;
    }

    for(int i = 0; i < ARRAY_SIZE; i++)
    {
        printf("%d\n", array[i]);
    }
}