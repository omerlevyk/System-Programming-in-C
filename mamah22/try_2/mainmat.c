#include <stdio.h>
#include <stdlib.h>
#include "mymat.c"

typedef float MAT_A[3][3] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
typedef float MAT_B[3][3] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
typedef float MAT_C[3][3] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
typedef float MAT_D[3][3] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
typedef float MAT_E[3][3] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
typedef float MAT_F[3][3] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
typedef float MAT_ARRAY[5] = {MAT_A,MAT_B,MAT_C,MAT_D,MAT_E,MAT_F};

int main() {

	char command;
	while(command != 8) {
		printf("Please enter your command below: \n");
		command = getchar();
		if (commend <= 0 || commend >= 9) {
			while(commend <= 0 || commend >= 9) {
				printf("Undefined command name\n");
				command = getchar();
			}
		}
		menu(commend);
	}
	return 0;
}
