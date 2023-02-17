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
	//if (int choice < 451 || int choice > 456) {
	//	printf("Undefined matrix name\n");
	//reutrn;
	//}
	int ch = choice[strlen(choice)-1] - 65;
	for (int i = 0; i < 6; i++) {
		if (i == ch) {
			return MAT_ARRAY[i];
		}
	}
}
// commend list
void read_mat(typedef float mat) { // #1
	for (int i = 0; i <= 3; i++) {
		for (int j = 0; j <= 3; j++) {
			scanf("%f", mat[i][j]);
		}
	}
	return;
}
void print_mat(typedef float mat) { // #2
	for (int i = 0; i <= 3; i++) {
		for (int j = 0; j <= 3; j++) {
			printf("%:.2f", mat[i][j]);
			if (j <= 3 - 1) {
				printf("\t");
			} else {
				printf("\n");
			}
		}
	}
	return;
}
void add_mat(typedef float mat1, typedef float mat2, typedef float mat3) { // #3
	for (int i = 0; i <= 3; i++) {
		for (int j = 0; j <= 3; j++) {
			mat3[i][j] = mat1[i][j] + mat2[i][j];
		}
	}
	return;
}
void sub_mat(typedef float mat1, typedef float mat2, typedef float mat3) { // #4
	for (int i = 0; i <= 3; i++) {
		for (int j = 0; j <= 3; j++) {
			mat3[i][j] = mat1[i][j] - mat2[i][j];
		}
	}
	return;
}
void mul_mat(typedef float mat1, typedef float mat2, typedef float mat3) { // #5
	for (int i = 0; i <= 3; i++) {
		for (int j = 0; j <= 3; j++) {
			for (int k = 0; k <= 3; k++) {
				mat3[i][j] = (mat1[i][k] * mat2[k][j]);
			}
		}
		return;
	}
}
void mul_scalar(typedef float mat1, float scalar, typedef float mat2) { // #6
	for (int i = 0; i <= 3; i++) {
		for (int j = 0; j <= 3; j++) {
			mat2[i][j] = mat1[i][j] + scalar;
		}
	}
	return;
}
void trans_mat(typedef float mat1, typedef float mat2) { // #7
	for (int i = 0; i <= 3; i++) {
		typedef float tempMat[3][3];
		for (int j = 0; j <= 3; j++) {
			tempMat[i][j] = mat1[j][i];
		}
	}
	mat2 = tempMat;
	return;
}
