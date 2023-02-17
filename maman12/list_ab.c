
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char list_ab() {
    printf("Enter your input here please:\n");
    char ch;
    char* str = (char*)malloc(sizeof(char)*10000); 
    int index = 0;
    int jdex = 0;
    while(EOF != ch) {
        ch = getchar();
        if (ch != EOF) {
            str[index++] = ch;   
        }
        if (isalnum(ch)) {
            jdex++;
        }
    }
    index--;
    printf("The input received is: %s", str);
    printf("The number of chars used is: %d\n", index);
    printf("The total summ of the alphanumeric chars is %d\n",jdex);  
    return ch;
}

int main() {

    char input1;
    input1 = list_ab();
}
