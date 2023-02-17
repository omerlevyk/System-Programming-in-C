#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mymat.h"

#define MAT_SIZE 4
typedef struct mat {
    float** index;
} mat;

static void setInMat(matPointer pmat, int i, int j, float num) {
    *(*((pmat -> index) +i ) + j) = num;
}
static float getNumFromMat(matPointer pmat, int i, int j) {
    return *(*((pmat -> index) +i) +j);
}
matPointer create_mat() {
    int i, j;
    matPointer tempMat;
    tempMat = (matPointer)malloc(sizeof(mat));
    if (tempMat) {
        tempMat -> index = (float **)malloc(MAT_SIZE*(sizeof(float*)));
        if (tempMat -> index) {
            for (i = 0; i < MAT_SIZE; i++) {
                *((tempMat -> index) +i) = (float*)malloc(MAT_SIZE*(sizeof(float)));
                if (!(*((tempMat -> index) +i))) {
                    for (j = 0; j < i; j++) {
                        free (*((tempMat -> index) +j));
                    }
                    return NULL;
                }
            }
        } else {
            free(tempMat);
            return NULL;
        }
    } else {
        return tempMat;
    }
}
void free_mat(matPointer pmat) {
    int i;
    for (i = 0; i< MAT_SIZE; i++) {
        free(*((pmat -> index) +i));
    }
    free(pmat);
}
/* commend list */
void read_mat(matPointer pmat, float* numList, int lastNum) {
	int i, j, counter = 0;
    for (i = 0; i < MAT_SIZE; i++) {
		for (j = 0; j < MAT_SIZE; j++) {
			if (lastNum >= counter) {
                setInMat(pmat, i, j, numList[counter++]);
            } else {
                setInMat(pmat, i, j, 0);
            }
		}
	}
	return;
}
void print_mat(matPointer pmat) {
	int i, j;
    for (i = 0; i < MAT_SIZE; i++) {
		for (j = 0; j < MAT_SIZE; j++) {
			printf("%:.2f", getNumFromMat(pmat, i, j));
			if (j < MAT_SIZE - 1) {
				printf("\t");
			} else {
				printf("\n");
			}
		}
	}
	return;
}
void add_mat(matPointer pmat1, matPointer pmat2, matPointer* pmat3) {
    int i, j;
    float tempNum;
    matPointer tempMat = create_mat();
    if (tempMat) {
        for (i = 0; i < MAT_SIZE; i++) {
		    for (j = 0; j < MAT_SIZE; j++) {
                tempNum = getNumFromMat(pmat1, i, j) + getNumFromMat(pmat2, i, j);
			    setInMat(tempMat, i, j, tempNum);
		    }
        }
        free_mat(*pmat3);
        *pmat3 = tempMat;
	} else {
        printf("Error 23\n");
    }
	return;
}
void sub_mat(matPointer pmat1, matPointer pmat2, matPointer* pmat3) {
    int i, j;
    float tempNum;
    matPointer tempMat = create_mat();
    if (tempMat) {
        for (i = 0; i < MAT_SIZE; i++) {
		    for (j = 0; j < MAT_SIZE; j++) {
                tempNum = getNumFromMat(pmat1, i, j) - getNumFromMat(pmat2, i, j);
			    setInMat(tempMat, i, j, tempNum);
		    }
        }
        free_mat(*pmat3);
        *pmat3 = tempMat;
	} else {
        printf("Error 23\n");
    }
	return;
}
void mul_mat(matPointer pmat1, matPointer pmat2, matPointer* pmat3) {
    int i, j, k;
    float tempNum;
    matPointer tempMat = create_mat();
    if (tempMat) {
        for (i = 0; i < MAT_SIZE; i++) {
		    for (j = 0; j < MAT_SIZE; j++) {
                tempNum = 0;
                for (k = 0; k < MAT_SIZE; k++) {
                    tempNum += getNumFromMat(pmat1, i, k) * getNumFromMat(pmat2, k, j);
                }
                setInMat(tempMat, i, j, tempNum);
		    }
        }
        free_mat(*pmat3);
        *pmat3 = tempMat;
	} else {
        printf("Error 25\n");
    }
	return;
}
void mul_scalar(matPointer pmat1, float scalar, matPointer* pmat2) {
    int i, j;
    float tempNum;
    matPointer tempMat = create_mat();
    if (tempMat) {
        for (i = 0; i < MAT_SIZE; i++) {
		    for (j = 0; j < MAT_SIZE; j++) {
                tempNum = scalar * getNumFromMat(pmat1, i, j);
			    setInMat(tempMat, i, j, tempNum);
		    }
        }
        free_mat(*pmat2);
        *pmat2 = tempMat;
	} else {
        printf("Error 26\n");
    }
	return;
}
void trans_mat(matPointer pmat1, matPointer* pmat2) {
    int i, j;
    float tempNum;
    matPointer tempMat = create_mat();
    if (tempMat) {
        for (i = 0; i < MAT_SIZE; i++) {
		    for (j = 0; j < MAT_SIZE; j++) {
                tempNum = getNumFromMat(pmat1, i, j);
			    setInMat(tempMat, j, i, tempNum);
		    }
        }
        free_mat(*pmat2);
        *pmat2 = tempMat;
	} else {
        printf("Error 27\n");
    }
	return;
}
