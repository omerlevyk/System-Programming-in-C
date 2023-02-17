#include <stdio.h>
#include <stdlib.h>
#include <mymat.h>

void menu(int commend) {
	if (commend == 1) {
		printf("Plese state your chosen matrix:\n");
		printf("MAT_A , MAT_B, MAT_C, MAT_D, MAT_E, MAT_F")
		printf("For a 4x4 matrix, Please enter your 16 chosen numbers with spaces in between then press enter:\n");
		printf("Plese noter that for each missing number, the cell will be 0.\n");
		read_mat()
	}
	if (commend == 2)
	if (commend == 3)
	if (commend == 4)
	if (commend == 5)
	if (commend == 6)
	if (commend == 7)
	
	return;
}
float chosen_mat() {
	char choice;
	printf("Plese state your choice matrix by insurting the right name:\n");
	printf("the options are:\nMAT_A , MAT_B, MAT_C, MAT_D, MAT_E, MAT_F\n");
	choice = getchar();
	if (choice == "MAT_A")
	if (choice == "MAT_B")
	if (choice == "MAT_C")
	if (choice == "MAT_D")
	if (choice == "MAT_E")
	if (choice == "MAT_F")
}
// commend list
void set_mat(int[] mat) { // #0
	for (int i = 0; i <= MAT_SIZE; i++) {
		for (int j = 0; j <= MAT_SIZE) {
			mat[i][j] = 0;
		}
	}
	return;
}
float read_mat(int [] mat) { // #1
	for (int i = 0; i <= MAT_SIZE; i++) {
		for (int j = 0; j <= MAT_SIZE; j++) {
			scanf("%f", mat[i][j]);
		}
	}
	return mat;
}
void print_mat(int[] mat) { // #2
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
void add_mat(int[] mat1, int[] mat2, int[] mat3) { // #3
	for (int i = 0; i <= MAT_SIZE; i++) {
		for (int j = 0; j <= MAT_SIZE; j++) {
			mat3[i][j] = mat1[i][j] + mat2[i][j];
		}
	}
	return;
}
void sub_mat(int[] mat1, int[] mat2, int[] mat3) { // #4
	for (int i = 0; i <= MAT_SIZE; i++) {
		for (int j = 0; j <= MAT_SIZE; j++) {
			mat3[i][j] = mat1[i][j] - mat2[i][j];
		}
	}
	return;
}
void mul_mat(int[] mat1, int[] mat2, int[] mat3) { // #5
	set_mat(mat3);
	for (int i = 0; i <= MAT_SIZE; i++) {
		for (int j = 0; j <= MAT_SIZE; j++) {
			for (int k = 0; k <= MAT_SIZE; k++) {
				mat3[i][j] += mat1[i][k] * mat2[k][j];
			}
		}
		return;
	}
}
void mul_scalar(int[] mat, float scalar) { // #6
	for (int i = 0; i <= MAT_SIZE; i++) {
		for (int j = 0; j <= MAT_SIZE; j++) {
			mat[i][j] += scalar;
		}
	}
	return;
}
void trans_mat(int[] mat1, int[] mat2) { // #7
	for (int i = 0; i <= MAT_SIZE; i++) {
		for (int j = 0; j <= MAT_SIZE; j++) {
			mat2[i][j] = mat1[j][i];
		}
	}
	return;
}
