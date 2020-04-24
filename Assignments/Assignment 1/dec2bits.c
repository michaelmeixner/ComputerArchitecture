#include <stdio.h>
#include <math.h>

void main()
{
    // This program reads in a value between 0 and 255
    // and outputs it in binary.

    int value, i, powerOfTwo, nextBit, rest;

    printf("Please input a value between 0 and 255: ");
    scanf("%d", &value);
    printf("\n");

    powerOfTwo = 128; // 2 to the 7th power
    rest = value;

    int array[7];

    for (int i = 7; i >= 1; i--)
    {
        nextBit = rest / powerOfTwo; // determine next bit     
        // printf("%d",nextBit);
        rest = rest - nextBit*powerOfTwo; // strip next bit off
        powerOfTwo = powerOfTwo / 2; // get ready to move to next bit
        array[i] = nextBit; //add current nextbit to array
        array[0] = rest; //add last bit to array
    }

    // printf("%d", rest); // last bit
    // printf(" is the binary equivalent of %d\n", value);

    if(array[6] == 1 && array[5] == 1 && array[4] == 1 && array[3] == 1 && array[2] == 0 && array[1] == 0 && array[0] == 0)
    {
        for(int i = 7; i >= 0; i--)
        {
            printf("%d", array[i]);
        }
        printf(" is infinity in 8-bit binary.\n");
        return;
    }
    else if(array[6] == 1 && array[5] == 1 && array[4] == 1 && array[3] == 1 && (array[2] == 0 || array[2] == 1) && (array[1] == 0 || array[1] == 1) && (array[0] == 0 || array[0] == 1))
    {
        for(int i = 7; i >= 0; i--)
        {
            printf("%d", array[i]);
        }
        printf(" is NaN in 8-bit binary.\n");
        return;
    }

    double exp1 = array[3] * 1;
    double exp2 = array[4] * 2;
    double exp3 = array[5] * 4;
    double exp4 = array[6] * 8;

    double fracBit1 = array[0] * 1;
    double fracBit2 = array[1] * 2;
    double fracBit3 = array[2] * 4;

    double totalFrac = 0;
    double totalExp = 0;
    if(array[6] == 0 && array[5] == 0 && array[4] == 0 && array[3] == 0)
    {
        totalExp = -6;
        totalFrac = (fracBit1 + fracBit2 + fracBit3) / 8;
    }
    else
    {
        totalExp = exp1 + exp2 + exp3 + exp4 - 7;
        totalFrac = (fracBit1 + fracBit2 + fracBit3 + 8) / 8;
    }

    double resultU = pow(2.0, totalExp) * totalFrac;

    double finalResult = 0;
    if(array[7] == 1)
    {
        finalResult = resultU * -1;
    }
    else
    {
        finalResult = resultU;
    }

    printf("%e\n", finalResult);
}