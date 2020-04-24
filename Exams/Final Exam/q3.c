#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <limits.h>

#define SIZE_1 1000000000
#define SIZE_2 INT_MAX - 1
#define SIZE_3 10000000
#define SIZE_4 31000003
#define SIZE_5 79197919

typedef struct NodeI
{
    int *ptr;
    struct NodeI *next;
} nodeI;

typedef struct Node2
{
    void *ptr;
    struct Node2 *next;
} node2;

int countIntAllocationsAtSize(int);
int countAllocationsAtSize(int);

int main()
{
    setlocale(LC_ALL,"");
    for(int i = 0; i < 10; i++)
    {
        printf("\nAllocated %'d Nodes of Size %'d Integers\n\n", countIntAllocationsAtSize(SIZE_1), SIZE_1);
    }

    // printf("\nAllocated %'d Nodes of Size %'d Integers\n\n", countIntAllocationsAtSize(SIZE_1), SIZE_1);
    // printf("\nAllocated %'d Nodes of Size %'d Integers\n\n", countIntAllocationsAtSize(SIZE_2), SIZE_2);
    // printf("\nAllocated %'d Nodes of Size %'d Integers\n\n", countIntAllocationsAtSize(SIZE_1), SIZE_1);


    // printf("\nAllocated %'d Nodes of Size %'d Bytes\n\n", countAllocationsAtSize(SIZE_1), SIZE_1);
    // printf("\nAllocated %'d Nodes of Size %'d Bytes\n\n", countAllocationsAtSize(SIZE_2), SIZE_2);
    // printf("\nAllocated %'d Nodes of Size %'d Bytes\n\n", countAllocationsAtSize(SIZE_1), SIZE_1);
}

int countIntAllocationsAtSize(int size)
{
    nodeI *root = NULL;
    nodeI *last = NULL;
    int numNodes = 0;
    double freed;
    while(1)
    {
        nodeI *nextNode = calloc(sizeof(nodeI), 1);
        if(nextNode)
        {
            nextNode->ptr = calloc(sizeof(int), size);
            if(nextNode->ptr)
            {
                numNodes++;
                if(last)
                {
                    last->next = nextNode;
                }
                else
                {
                    root = nextNode;
                }
                last = nextNode;
            }
            else
            {
                free(nextNode), nextNode = NULL;
                break;
            }
        }
        else
        {
            break;
        }
    }

    nodeI *prev = root;
    nodeI *curr = root->next;
    while(prev)
    {
        free(prev->ptr);
        free(prev);
        prev = curr;
        curr = curr->next;
        free(root->next);
    }
    printf("%03.2lf%% Freed\r", ((freed++ / numNodes)*100));

    return numNodes;
}


int countAllocationsAtSize(int size)
{
    node2 *root = NULL;
    node2 *last = NULL;
    int numNodes = 0;
    double freed;
    while(1)
    {
        node2 *nextNode = calloc(sizeof(node2), 1);
        if(nextNode)
        {
            nextNode->ptr = malloc(size);
            if(nextNode->ptr)
            {
                numNodes++;
                if(last)
                {
                    last->next = nextNode;
                }
                else
                {
                    root = nextNode;
                }
                last = nextNode;
            }
            else
            {
                free(nextNode), nextNode = NULL;
                break;
            }
        }
        else
        {
            break;
        }
    }

    node2 *prev = root;
    node2 *curr = root->next;
    while(curr)
    {
        free(prev->ptr);
        free(prev);
        prev = curr;
        curr = curr->next;
    }
    printf("%03.2lf%% Freed\r", ((freed++ / numNodes)*100));

    return numNodes;
}