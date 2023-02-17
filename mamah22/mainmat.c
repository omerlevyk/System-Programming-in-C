#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mymat.h"

/* Navigation Functions: */
enum boolean {OUT, IN};
int skip;
matPointer MAT_ARRAY[6];

int getMatLoc(char* ch) {
    int i;
    char* tempMat[6] = {"MAT_A", "MAT_B", "MAT_C", "MAT_D", "MAT_E", "MAT_F"};
    for (i = 0; i < 6; i++) {
        if (strcmp(ch, tempMat[i])) {
            return i;
        }
    }
    return -1;
}

int getMat() {
    char* buffer = NULL;
    int matLoc;
    scanf("%s", buffer);
    if (buffer) {
        matLoc = getMatLoc(buffer);
        if (matLoc != -1) {
            return matLoc;
        } else {
            printf("Error 4\n");
        }
        free(buffer);
    } else {
        printf("Error 5\n");
        return -1;
    }
}

/* Command Functions:*/
int funTo_read_mat() { /* #1 */
    int i = 0, status;
    int pmat1;
    float tempArray[16], *next;
    next = NULL;
    if ((pmat1 = getMat()) != -1) {
        while(jumpStep() && i<16) {
            if ((next = getNum())) {
                tempArray[i++] = *next;
                free(next);
            } else {
                printf("Error 6\n");
                return 1;
            }
        }
        status = runToEnd();
        if (i >= 16 || status) {
            read_mat(MAT_ARRAY[pmat1], tempArray, i);
        } else {
            printf("Error 6\n");
        }
    } else {
        return 1;
    }
    return 0;
}
int funTo_print_mat() { /* #2 */
    int pmat1;
    if ((pmat1 = getMat()) != -1) {
        if (runToEnd()) {
            print_mat(MAT_ARRAY[pmat1]);
        } else {
            printf("Error 8\n");
        }
    } else {
        return 1;
    }
    return 0;
}
int funTo_add_mat() { /* #3 */
    int pmat1, pmat2, pmat3;
    if ((pmat1 = getMat()) != -1) {
        if (jumpStep() && (pmat2 = getMat()) != -1 && jumpStep()) {
            if ((pmat3 = getMat()) != -1) {
                if (runToEnd()) {
                    add_mat(MAT_ARRAY[pmat1], MAT_ARRAY[pmat2], &MAT_ARRAY[pmat3]);
                } else {
                    printf("Error 9\n");
                }
            } else {
                return 1;
            }
        } else {
            printf("Error 10\n");
            return 1;
        }
    } else {
        return 1;
    }
    return 0;
}
int funTo_sub_mat() { /* #4 */
    int pmat1, pmat2, pmat3;
    if ((pmat1 = getMat()) != -1) {
        if (jumpStep() && (pmat2 = getMat()) != -1 && jumpStep()) {
            if ((pmat3 = getMat()) != -1) {
                if (runToEnd()) {
                    sub_mat(MAT_ARRAY[pmat1], MAT_ARRAY[pmat2], &MAT_ARRAY[pmat3]);
                } else {
                    printf("Error 11\n");
                }
            } else {
                return 1;
            }
        } else {
            printf("Error 12\n");
            return 1;
        }
    } else {
        return 1;
    }
    return 0;
}
int funTo_mul_mat() { /* #5 */
    int pmat1, pmat2, pmat3;
    if ((pmat1 = getMat()) != -1) {
        if (jumpStep() && (pmat2 = getMat()) != -1 && jumpStep()) {
            if ((pmat3 = getMat()) != -1) {
                if (runToEnd()) {
                    mul_mat(MAT_ARRAY[pmat1], MAT_ARRAY[pmat2], &MAT_ARRAY[pmat3]);
                } else {
                    printf("Error 13\n");
                }
            } else {
                return 1;
            }
        } else {
            printf("Error 14\n");
            return 1;
        }
    } else {
        return 1;
    }
    return 0;
}
int funTo_mul_scalar() { /* #6 */
    int pmat1, pmat2;
    float* nextnum = NULL;
    if ((pmat1 = getMat()) != -1) {
        if (jumpStep()) {
            if (nextnum = getNum()) {
                if (jumpStep()) {
                    if ((pmat2 = getMat()) != -1) {
                        if (runToEnd()) {
                            mul_scalar(MAT_ARRAY[pmat1], *nextnum, &MAT_ARRAY[pmat2]);
                        } else {
                            printf("Error 13\n");
                        }
                    } else {
                        free(nextnum);
                        return 1;
                    }
                } else {
                    printf("Error 15\n");
                    free(nextnum);
                    return 1;
                }
                free(nextnum);
            } else {
                printf("Error 16\n");
                return 1;
            }
        } else {
            printf("Error17\n");
            return 1;
        }
    } else {
        return 1;
    }
    return 0;
}
int funTo_trans_mat() { /* #7 */
	int pmat1, pmat2;
	if((pmat1 = getMat()) != -1) {
		if(jumpStep()) {
			if((pmat2 = getMat()) != -1) {
				if(runToEnd()) {
					trans_mat(MAT_ARRAY[pmat1], &MAT_ARRAY[pmat2]);
				} else {
					printf("Error 13\n");
				}				
			} else {
                return 1;
            }		
		} else {
			printf("Error 18\n");		
			return 1;
		}
	}
	else {
        return 1;
    }
	return 0;
}
int funTo_stop() { /* #8 */
    int i;
    for(i = 0; i < 6; i++) {
        free_mat(MAT_ARRAY[i]);
    }
    skip = OUT;
    runToEnd();
    return 0;
}
int funTo_errors() { /* #Errors */
    printf("Error 19\n");
    runToEnd();
    return 0;
}


int main() {
	int CommenNum, i, j;
	char *buffer = NULL;
	char *charCommend[8] = {"read_mat", "print_mat", "add_mat", "sub_mat", "mul_mat", "mul_scalar", "trans_mat", "stop"};
	int (*function[9])() = {funTo_read_mat, funTo_print_mat, funTo_add_mat, funTo_sub_mat, funTo_mul_mat, funTo_mul_scalar, funTo_trans_mat, funTo_stop, funTo_errors};
	for(i = 0; i < 6; i++) {
		MAT_ARRAY[i] = create_mat();
		if(!MAT_ARRAY[i]) {
			printf("Unable to create all 6 mat.\n");
			for(j = 0; j < i; j++) {
				free_mat(MAT_ARRAY[j]);
			}
			exit(0);
		}
	}
	skip = IN;
	while(skip) {
        printf("$:");
		buffer = getChar();
		if(buffer) {
			CommenNum = 8;
            i = 0;
			for( i = 0; i < 8 ; i++) {
				if(strcmp(buffer, charCommend[i]) == 0) {
					CommenNum = i;
				}
			}
			if(function[CommenNum]()) {
				if(isLast()) {
					printf("Error 1\n");
					funTo_stop();
				} else {
					runToEnd();
				}				
			}					
			free(buffer);
		} else {
			if(isLast()) {
				printf("Error 2\n");
				funTo_stop();
			} else {
				printf("Error 3\n");
				runToEnd();
			}
		}
	}
	return 0;
}
