#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu(char command) {

	if (strcmp(command, "read_mat")) {
		read_mat(chosen_mat());
	} else if (strcmp(command, "print_mat")) {
		print_mat(chosen_mat());
	} else if (strcmp(command, "add_mat")) {
		add_mat(chosen_mat(), chosen_mat(), chosen_mat());
	} else if (strcmp(command, "sub_mat")) {
		sub_mat(chosen_mat(), chosen_mat(), chosen_mat());
	} else if (strcmp(command, "mul_mat")) {
		mul_mat(chosen_mat(), chosen_mat(), chosen_mat());
	} else if (strcmp(command, "mul_scalar")) {
		float scalar;
		typedef float tempMat = chosen_mat();
		scanf("%f", &scalar);
		mul_scalar(tempMat, scalar, chosen_mat());
	} else if (strcmp(command, "trans_mat")) {
		trans_mat(chosen_mat(), chosen_mat());
	} else if (strcmp(command, "stop")) {
		return 8;
	}  
	return;
}
typedef float chosen_mat() {
	char choice = getchar();
	int ch = choice[strlen(choice)-1] - 65;
		for (int i = 0; i < 6; i++) {
			if (i == ch) {
				return MAT_ARRAY[i];
			}
		}
}
// commend list
void read_mat(typedef float mat) { // #1
	for (int i = 0; i <= MAT_SIZE; i++) {
		for (int j = 0; j <= MAT_SIZE; j++) {
			scanf("%f", mat[i][j]);
		}
	}
	return;
}
void print_mat(typedef float mat) { // #2
	for (int i = 0; i <= MAT_SIZE; i++) {
		for (int j = 0; j <= MAT_SIZE; j++) {
			printf("%:.2f", mat[i][j]);
			if (j <= MAT_SIZE - 1) {
				printf("\t");
			} else {
				printf("\n");
			}
		}
	}
	return;
}
void add_mat(typedef float mat1, typedef float mat2, typedef float mat3) { // #3
	for (int i = 0; i <= MAT_SIZE; i++) {
		for (int j = 0; j <= MAT_SIZE; j++) {
			mat3[i][j] = mat1[i][j] + mat2[i][j];
		}
	}
	return;
}
void sub_mat(typedef float mat1, typedef float mat2, typedef float mat3) { // #4
	for (int i = 0; i <= MAT_SIZE; i++) {
		for (int j = 0; j <= MAT_SIZE; j++) {
			mat3[i][j] = mat1[i][j] - mat2[i][j];
		}
	}
	return;
}
void mul_mat(typedef float mat1, typedef float mat2, typedef float mat3) { // #5
	mat3 = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
	for (int i = 0; i <= MAT_SIZE; i++) {
		for (int j = 0; j <= MAT_SIZE; j++) {
			for (int k = 0; k <= MAT_SIZE; k++) {
				mat3[i][j] += (mat1[i][k] * mat2[k][j]);
			}
		}
		return;
	}
}
void mul_scalar(typedef float mat, float scalar) { // #6
	for (int i = 0; i <= MAT_SIZE; i++) {
		for (int j = 0; j <= MAT_SIZE; j++) {
			mat[i][j] += scalar;
		}
	}
	return;
}
void trans_mat(typedef float mat1, typedef float mat2) { // #7
	for (int i = 0; i <= MAT_SIZE; i++) {
		typedef float tempMat[3][3];
		for (int j = 0; j <= MAT_SIZE; j++) {
			tempMat[i][j] = mat1[j][i];
		}
	}
	mat2 = tempMat;
	return;
}
