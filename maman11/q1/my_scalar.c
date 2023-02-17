#include <stdio.h>
/*
* scalar_product - the main function received a number (for the arry size) and two vectors (placed in arrays) vec1, vec2 and calculate the scalar product of those two vectoers.
*
* Authors - Elizabeth Rodkevich, Omer Levy
*/

void main() {
	int size, summ;
	
	printf("Please insert the vactors size below: \n");
	scanf("%d", &size);
	
	int vec1 [size];
	int vec2 [size];
	printf("Please insert the first vactor below with spece between each intger: \n");
	for (int i = 0; i < size; i++) {
		if (i == size -1) {
			vec1[i] = '\0';
		}
		scanf("%d", &vec1[i]);
	}
	printf("First vector received. \n");
	
	printf("Please insert the first vactor below with spece between each intger: \n");
	for (int i = 0; i < size; i++) {
		if (i == size -1) {
			vec2[i] = '\0';
		}
		scanf("%d", &vec2[i]);
	}
	printf("Second vector received. \n");
	
	summ = scalar_product(vec1, vec2, size);
	printf("the scalar product from the two vectors is = %d \n" , summ);
}
int scalar_product (int vector1 [], int vector2 [], int size) {
	int product_summ = 0;
	for (int i = 0; i < size; i++) {
		product_summ += vector1[i]*vector2[i];
	}
	return product_summ;
}
	
	
	
	
	
	
	
	
