#include <stdio.h>

void showBytes(char *, int);
void reverseBytes(char *, int);
void printAll(char *);

int main()
{ 
        char *ptr = "Hello"; 
        printf("Happy Feast of St. Lawrence Justinian!\n"); 
        showBytes(ptr, sizeof(char)); 
        int x = 15; 
        showBytes((char *)&x, sizeof(int)); 
        reverseBytes(ptr, sizeof(char)); 
        reverseBytes((char *)&x, sizeof(int));
        printAll((char *)&x); 
}

void showBytes(char *ptr, int length) 
{ 
    for(int i = 0; i < length; i++) 
    { 
        printf("%.2x ", *(ptr + i)); 
    } 
    printf("\n"); 
}

void reverseBytes(char *ptr, int length)
{
    for(int i = length-1; i >= 0; i--)
    {
        printf("%.2x ", *(ptr + i)); 
    }
    printf("\n");
}

void printAll(char *ptr)
{
    while(1)
    {
        printf("%c ", *ptr++);
    }
}