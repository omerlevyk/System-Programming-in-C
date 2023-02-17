#include <stdio.h>
#include <stdlib.h>
#include <mymat.h>
#include <mymat.c>

int main() {
	set_mat(MAT_A);
	set_mat(MAT_B);
	set_mat(MAT_C);
	set_mat(MAT_D);
	set_mat(MAT_E);
	set_mat(MAT_F);
	int command;
	printf("Command list:\n1-set matrix\t2-print matrix\t3-add matrices\t4-subtract matrices\n5-multiply matrices\t6-multiply matrix with scalar\t7-transpose matrix\t8-stop progrem\n");
	whlie(command != 8) {
		printf("Please enter your command below: \n");
		scanf("%d", &command);
		if (commend <= 0 || commend >= 9) {
			whlie(commend <= 0 || commend >= 9) {
				printf("Invalid command, please try again\n");
				scanf("%d", &command);
			}
		}
		menu(commend);
	}
	//printf("stop\n");
	return 0;
}