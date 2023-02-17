#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
		if (command <= 0 || command >= 9) {
			while(command <= 0 || command >= 9) {
				printf("Undefined command name\n");
				command = getchar();
			}
		}
		menu(command);
	}
	return 0;
}

typedef struct cmdSet {
	char cmd;
	char mat1;
	char mat2;
	char mat3;
	int sclr;
} CmdType

int main() {
	char *cmdList[8] = {"read_mat", "print_mat", "add_mat", "sub_mat", "mul_mat", "mul_scalar", "trans_mat", "stop"};
	CmdType order;
	order.cmd = getchar();
	for (int i = 0; i <= sizeof(char)*cmdList; i++) {
		if (strcmp(cmdList[i], order.cmd)) {
			if (i != 8) {
				order.mat1 = getchar();
				if (i > 2 && i < 6) {
					order.mat2 = getchar();
					order.mat3 = getchar();
				} else if (i == 6) {
					scan("%f", order.sclr);
					order.mat2 = getchar();
				} else if (i == 7) {
					order.mat2 = getchar();
				}
			}
		} else if (i == sizeof(char)*cmdList && !strcmp(cmdList[i], order.cmd)) {
			printf("Undefined command name\n");
		}
	}
}