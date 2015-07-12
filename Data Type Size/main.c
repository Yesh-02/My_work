#include <stdio.h>
void signedRange(int size)
{
    int bit = (8 * size) - 1 ;
    int from = - (1 << (bit));
    int to =  (1 << (bit));
    printf("%d to %d\n\n", from, to - 1);
}
void unsignedRange(int size)
{
    int bit = size * 8;

    unsigned int to = 2*(1 << (bit-1));
    
    printf("%u to %u \n\n", 0, to - 1);
}
int main()
{
    printf("Size of signed char is %lu\n",sizeof(char));
    printf("Range of signed char is ");
    signedRange(sizeof(char));
    
    
    printf("Size of unsigned char is %lu\n",sizeof(unsigned char));
    printf("Range of unsigned char is ");
    unsignedRange(sizeof(unsigned char));
    
    printf("Size of signed short is %lu\n",sizeof(short));
    printf("Range of signed short is ");
    signedRange(sizeof(short));
    
    printf("Size of unsigned short is %lu\n",sizeof(unsigned short));
    printf("Range of unsigned short is ");
    unsignedRange(sizeof(unsigned short));
    
    printf("Size of signed int is %lu\n",sizeof(int));
    printf("Range of signed int is ");
    signedRange(sizeof(int));
    
    printf("Size of ubsigned int is %lu\n",sizeof(unsigned int));
    printf("Range of unsigned int is  ");
    unsignedRange(sizeof(unsigned int));
    
    return 0;
}