#include <stdio.h>
#include <stdlib.h>

#define INT_ARRAY_SIZE 10

int main()
{
    int *intArray = NULL;
    intArray = (int *)malloc(INT_ARRAY_SIZE * sizeof(int));

    if(intArray == NULL)
    {
        printf("Dude. Please stahp.");
        return 0;
    }

    for(int i = 0; i < INT_ARRAY_SIZE; i++)
    {
        //intArray[i] = i;
        *(intArray + i) = i; //uses the address of intArray at i and adds i to that space
        //intArray + (i* sizeof(int)); <-- this is what the compiler does when you run this ^^^ line (line 20)
    }

    for(int i = 0; i < INT_ARRAY_SIZE; i++)
    {
        printf(" %d, ", intArray[i]);
    }

    printf("\n");

    free(intArray), intArray = NULL; //setting the pointer to NULL because we don't own the RAM it was pointing to anymore
}