// Michael Meixner, Lab 7
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DATA_FILE "timedata.dat"

// start assignment 3
int parseInt(int input, int *hours, int *minutes, int *seconds)
{
    int mask = 63;
    int result = 0;
    asm(
        "movl %4, (%1)\n\t"
        "movl %4, (%2)\n\t"
        "movl %4, (%3)\n\t"
        "shrl $12, (%1)\n\t"
        "shrl $6, (%2)\n\t"
        "and %5, (%2)\n\t"
        "and %5, (%3)\n\t"
        :"=r"(result)
        :"r"(hours), "r"(minutes), "r"(seconds), "r"(input), "r"(mask)
        :"%r8", "%r9", "%r10", "%r11", "%r12"
    );
    return result;
}

int packInt(int hours, int minutes, int seconds)
{
    int result = 0;
    asm(
        "movl %1, %0\n\t"
        "shl $6, %0\n\t"
        "addl %2, %0\n\t"
        "shl $6, %0\n\t"
        "addl %3, %0\n\t"
        :"=r"(result)
        :"r"(hours), "r"(minutes), "r"(seconds)
        :"%r8", "%r9", "%r10", "%r11", "%r12"
    );
    return result;
}

int main() 
{
    printf("\n\nFile Data:\n");
    FILE *inputFile = NULL;
    if((inputFile = fopen(DATA_FILE, "r")) == NULL) 
    {
         printf("Error opening file %s for input!\n", DATA_FILE);
        exit(0);
    }

    int secondtime = 0;
    while(!feof(inputFile))
    {
        int time = 0, hours = 0, minutes = 0, seconds = 0;
        if(fread(&time, sizeof(int), 1, inputFile))
        {
            parseInt(time, &hours, &minutes, &seconds);
            printf("%d = %02d:%02d:%02d\n", time, hours, minutes, seconds);
            secondtime = packInt(hours, minutes, seconds);
            printf("Original time is %d and pack function time is %d\n", time, secondtime);
        }
    }

    int hours = 0;
    int minutes = 0;
    // int minutesMask = 4032; 
    int seconds = 0;
    int mask = 63;
    while(!feof(inputFile)) 
    {
        int time = 0;
        if(fread(&time, sizeof(int), 1, inputFile)) 
        {
            //do work here
            hours = time >> 12;
            // minutes = (time & minutesMask) >> 6;
            minutes = (time >> 6) & mask;
            seconds = (time) & mask;
        }
    }
    printf("%02d:%02d:%02d\n", hours, minutes, seconds);
    fclose(inputFile), inputFile = NULL;
}