// CSCI-4200 Lab 6 - code supplied in text (Section 3.10.3)
// Michael Meixner
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 8

char *gets(char *s)
{
    int c;
    char *dest = s;
    int overflow = 1;

    while ((c = getchar()) != '\n' && c != EOF && overflow++ < ARRAY_SIZE)
        *dest++ = c; /* No bounds checking! */

    if (c == EOF && dest == s)
       return NULL; /* No characters were read */
    
    /* else terminate string and return it */
    *dest++ = '\0';
    return s;
}

/* Read input line and write it back */
void echo()
{
    char buf[8];  /* Way too small! */
    gets(buf);
    puts(buf);
}

void main()
{
  printf("Type a string: ");
  echo();   
}