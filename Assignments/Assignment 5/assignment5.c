// Michael Meixner, Assignment 5
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int page[5];
    int memory[3];
    int track[3];

    for(int i = 0; i < 5; i++)
    {
        page[i] = i;
    }

    for(int i = 0; i < 3; i++)
    {
        track[i] = i;
        memory[i] = i;
    }

    int choice;
    int dest;
    int first;
    int second;
    int flag = 0;
    int flag1 = 0;
    int flag2 = 0;

    while(choice != 0)
    {
        printf("0) Exit\n");
        printf("1) Add Numbers\n");
        printf("2) Print\n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 2:
            if(flag == 1)
            {
                printf("Data Changed. Saving Data to Page.\n\n");
                page[track[0]] = memory[0];
            }
            if(flag1 == 1)
            {
                printf("Data Changed. Saving Data to Page.\n\n");
                page[track[1]] = memory[1];
            }
            if(flag2 == 1)
            {
                printf("Data Changed. Saving Data to Page.\n\n");
                page[track[2]] = memory[2];
            }
            for(int i = 0; i < 5; i++)
            {
                printf("%d, ", page[i]);
            }
            printf("\n\n");
            break;

            case 1:
            printf("Destination Page Index?\n");
            scanf("%d", &dest);
            if(track[0] == dest)
            {
                printf("Page Already Loaded.\n\n");
            }
            else
            {
                if(flag == 1)
                {
                    printf("Data Changed. Saving Data to Page.\n\n");
                    page[track[0]] = memory[0];
                }
                printf("Evicting page %d. Loading page %d.\n\n", track[0], page[dest]);
                memory[0] = page[dest];
                track[0] = dest;
                flag = 0; //set flag as 1 after addition is complete
            }

            printf("First Page Index?\n");
            scanf("%d", &first);
            if(track[1] == first)
            {
                printf("Page Already Loaded.\n\n");
            }
            else
            {
                if(flag1 == 1)
                {
                    printf("Data Changed. Saving Data to Page.\n\n");
                    page[track[1]] = memory[1];
                }
                printf("Evicting page %d. Loading page %d.\n\n", track[1], page[first]);
                memory[1] = page[first];
                track[1] = first;
                flag1 = 0; //set flag as 1 after addition is complete
            }

            printf("Second Page Index?\n");
            scanf("%d", &second);
            if(track[2] == second)
            {
                printf("Page Already Loaded.\n\n");
            }
            else
            {
                if(flag2 == 1)
                {
                    printf("Data Changed. Saving Data to Page.\n\n");
                    page[track[2]] = memory[2];
                }
                printf("Evicting page %d. Loading page %d.\n\n", track[2], page[second]);
                memory[2] = page[second];
                track[2] = second;
                flag2 = 0; //set flag as 1 after addition is complete
            }

            memory[0] = memory[1] + memory[2];
            flag = 1;
            flag1 = 1;
            flag2 = 1;

            break;

            case 0:
            choice = 0;
            break;

            default:
            break;
        }
    }
}