#include <stdio.h>

/*
* find_bits - the main function received two numbers x,y
* then create to arrays in the length of 32 (symbolize the 32 bits) arr1, arr2
* which contain x,y in binery using the function numToBit() and compar each cell
* in the to array and search matching cells with the 1 value.
* 
* Authors - Elizabeth Rodkevich ,omer levy
*/


void main() {
    unsigned long x, y;
    int arr1[32] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int arr2[32] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    printf("Please enter the first number\n");
    scanf("%lu", &x);
    printf("The first nuber is: %lu\n", x);
    printf("Please enter the second number\n");
    scanf("%lu", &y);
    printf("The second nuber  is: %lu\n", y);
    numToBit(x, arr1);
    numToBit(y, arr2);
    //comper arr1, arr2
    int count = 0;
    for (int i = 0; i <= 32; i++) {
        if (arr1[i] == arr2[i] && arr1[i] == 1) {
            count++;
        }
    }
    printf("the number of Bits that was found is: %d \n", count);
}

void numToBit(unsigned long x, int array[]) {
    for (int i = 0; x > 0; i++) {
        array[i] = x % 2;
        x = (unsigned long)x / 2;
    }
}
