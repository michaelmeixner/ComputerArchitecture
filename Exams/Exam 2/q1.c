#include <stdio.h>

#define PACKED_SIZE 14

int main()
{

    int packed[PACKED_SIZE] = {0x44656172, 0x204c6f72, 0x642c2070, 0x6c656173, 0x65206c65, 0x74207468, 0x69732063, 0x6f646520, 0x776f726b, 0x2c20616e, 0x64206d65, 0x20706173, 0x732e2041, 0x6d656e2e};
    char message[PACKED_SIZE * 4 + 1] = {0};
    //do your work here
    
    for(int i = 0, a = 0; i < PACKED_SIZE; i++)
    {
        message[a++] = packed[i] >> 24;
        message[a++] = packed[i] >> 16 & 0xFF;
        message[a++] = packed[i] >> 8 & 0xFF;
        message[a++] = packed[i] & 0xFF;
    }
    printf("%s\n", message);

}