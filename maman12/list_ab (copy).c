#include <stdio.h>
#include <stdlib.h>

// ch = num_of_char, current_size = size of cahr
#define DEF_SIZE 16
char* list_ab (FILE* fun) {
	int* total_char[DEF_SIZE];
	int index = 0;
	char* str = (char*) malloc (DEF_SIZE);
	int curr_alp_char;
	int current_size = DEF_SIZE;
	unsigned int length = 0;
	//int char_summ = 0, num_of_char = 0;
	str = (char*) realloc (NULL, sizeof(char)*current_size);
	if (str == NULL) {
		return NULL;
	}
	while (EOF != (curr_alp_char = fgetc(fun))) {
		printf("Hello\n");
		str[length++] = curr_alp_char;
		total_char[index++] = curr_alp_char;
		if (length == current_size) {
			current_size += 16;
			str = (char*) realloc(str, sizeof(char)*current_size);
			if (str == NULL) {
				return NULL;
			}
		}
		str[length++] = '\0';
		
		//char_summ = curr_alp_char;
		//num_of_char = current_size;
		
		printf("The input received is: %s\n", &str);
		printf("The number of chars used is: %d\n", current_size);
		printf("The total summ of the alphanumeric chars is %d\n", curr_alp_char);
		
		return (char*) realloc(str, sizeof(current_size)*length);
	}
}


void main () {
	char* input1;
	//int char_summ = 0, num_of_char = 1;
	input1 = list_ab(stdin);
	
	free(input1);

}



