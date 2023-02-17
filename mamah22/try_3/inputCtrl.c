#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputCtrl.h"

char buffer[100];
static int index = -1;

static char getNext() {
    if (index > -1) {
        return buffer[index--];
    }
    return getChar();
}
static void setNext(char ch) {
    buffer[++index] = ch;
    return;
}

float* getNum() {
    float* num = NULL;
    char ch;
    int signal = 1;
    int counter = 0;
    char* buffer = (char*)calloc(100,sizeof(char));
    if (buffer) {
        num = (float*)malloc(sizeof(float));
        if (num) {
            jumpSpace();
            ch = getNext();
            if (ch == EOF || ch == '\n') {
                printf("Error 20\n");
                setNext(ch);
                free(buffer);
                free(num);
                return NULL;
            }
            if (ch == '-') {
                buffer[counter++] = ch;
                ch = getNext();
            }
            do {
                if (ch >= '0' && ch <= '9') {
                    buffer[counter++] = ch;
                } else if (signal && ch == '.') {
                    buffer[counter++] = ch;
                    signal = 0;
                } else {
                    setNext(ch);
                    printf("Error 20\n");
                    free(buffer);
                    free(num);
                    return NULL;
                }
            } while ((ch = getNext()) != EOF && isspace(ch) && ch != ',' && counter <= 100);
            setNext(ch);
            *num = atof(buffer);
            free(buffer);
        } else {
            printf("Error 21\n");
        }
    } else {
        printf("Error 22\n");
    }
    return num;
}
char* getChar() {
    char* buffer = NULL;
    char ch;
    jumpSpace();
    buffer = (char*)calloc(100, sizeof(char));
    if (buffer) {
        int i = -1;
        while ((ch = getNext()) != EOF && isspace(ch) && ch != ',' && i <= 100) {
            i++;
            *(buffer + i) = ch;
        }
        setNext(ch);
        if (i < 0) {
            free(buffer);
            return NULL;
        }
    } else {
        return NULL;
    }
    return buffer;
}
int isLast() {
    char ch = getNext();
    setNext(ch);
    if (ch = EOF) {
        return 1;
    } else {
        return 0;
    }
}
void jumpSpace() {
    char ch;
    jumpSpace();
    ch = getNext();
    if (strcmp(ch, ',')) {
        return 1;
    } else {
        setNext(ch);
        return;
    }
}
int runToEnd() {
    char ch;
    int num = 1;
    while ((ch = getNext()) != EOF && ch != '\n') {
        if (!isspace(ch)) {
            num = 0;
        }
    }
    if (ch == EOF) {
        setNext(EOF);
    }
    return num;
}
int jumpStep() {
    char ch;
    while ((ch = getNext()) != EOF && isspace(ch) && ch != '\n') {
        setNext(ch);
    }
    return 0;    
}