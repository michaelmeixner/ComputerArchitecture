// Michael Meixner, assignment 4
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VARIABLES "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789_"

int main(int argc, char *argv[]) //argc asks how many arrays of characters (strings) are in your array; argv is your array (character pointer)
{
    if(argc < 3) {
        printf("Usage: assignment4 x yyy.c where x is a number between 0 and 2 and yyy.c is a C source file\n");
        return 0;
    }

    long optLevel = strtol(argv[1], NULL, 10); //convert string to long; 1st arg is the string; 2nd arg is ; 3rd arg is base of number you're expecting (base 10 here)
    FILE *fp = NULL, *thisOne; 

    if((fp = fopen(argv[2], "r")) != NULL) //open file for reading
    {
        int looping = 0;
        char out[100];

        strcpy(out, argv[2]);
        out[strlen(out) - 2] = '\0';
        strcat(out, "_modified.c");
        thisOne = fopen(out, "w");

        char *line = NULL;
        int lineNum = 0;
        size_t len = 0;
        ssize_t charsRead;
        char buffer[2048];
        buffer[0] = '\0';

        while(!feof(fp)) //while not end of file
        {
            // for()
            if((charsRead = getline(&line, &len, fp)) != -1) 
            { //read the file with getline function; &line makes buffer for you; 
                // printf("Retrieved line of length %zu:\n", charsRead);
                // printf("%d) %s\n", ++lineNum, line);
                char *forPtr = NULL;
                if((forPtr = strstr(line, "for")) != NULL) //strstr function looks for a substring (string within string) "for" and returns a pointer to the location of "for"
                {
                    int index = 0;
                    while(forPtr[index] != ';')
                    {
                        fputc(forPtr[index++], thisOne);
                    }

                    while(forPtr[index] != '<')
                    {
                        fputc(forPtr[index++], thisOne);
                    }
                    fprintf(thisOne, "-1");

                    while(forPtr[index] != '+')
                    {
                        fputc(forPtr[index++], thisOne);
                    }
                    fprintf(thisOne, "+= 2) {\n");
                    looping = 1;
                }
                else if(looping)
                {
                    if(strchr(line, '}'))
                    {
                        fprintf(thisOne, "%s", buffer);
                        char iPtr;
                        int forIndex = 0;
                        for(iPtr = buffer[forIndex++]; iPtr != '\0'; iPtr = buffer[forIndex++])
                        {
                            fputc(iPtr, thisOne);
                            if(iPtr == 'i' && !strchr(VARIABLES, buffer[forIndex - 2]) && !strchr(VARIABLES, buffer[forIndex]))
                            {
                                fputc('+', thisOne);
                                fputc('1', thisOne);
                            }
                        }
                        looping = 0;
                    }
                    strcat(buffer, line);
                }
                else
                {
                    fprintf(thisOne, "%s", line);
                }
            }
        }
        fclose(fp);
        if(line)
        {
            free(line), line = NULL; //free up memory; give it back to computer and get rid of pointer so you don't use it again accidentally
        }
    } else {
        printf("Error opening file: %s\n", argv[2]);
    }
}