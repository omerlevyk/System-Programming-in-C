#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputCtrl.h"

/* Operation on the MAT list: */
typedef struct mat* matPointer;
static void setInMat(matPointer ,int , int , float);
static float getNumFromMat(matPointer , int , int);
matPointer create_mat();
void free_mat(matPointer);

/* Command menu: */
void read_mat(matPointer , float* , int );
void print_mat(matPointer);
void add_mat(matPointer, matPointer, matPointer*);
void sub_mat(matPointer, matPointer, matPointer*);
void mul_mat(matPointer, matPointer, matPointer* pmat3);
void mul_scalar(matPointer, float, matPointer*);
void trans_mat(matPointer, matPointer*);