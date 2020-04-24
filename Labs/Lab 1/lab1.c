#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main()
{
    int seconds = rand() % 10;
    int randomInt = rand() % 10;

    for(int i = 0; i < randomInt; i++)
    {
        sleep(seconds);
        printf("\a*Bell Sound*\n");
    }
}