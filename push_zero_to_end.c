#include <stdio.h>
#define SIZE 10

int main(void)
{
	int input[SIZE] = {1,2,6,0,5,2,0,0,12,0};
	int *ptr = input;
	int tmp, i;
	
	for (i = 0; i < SIZE; i++)
		printf("%d ", input[i]);

	printf("\n\n");

	for (i = 1; i < SIZE; i++) {
		printf("ptr = %d input = %d\n", *ptr, input[i]);

		if (*ptr == 0 && input[i] == 0)
			continue;

		if (*ptr == 0 && input[i] != 0) {
			tmp = *ptr;
			*ptr = input[i];
			input[i] = tmp;
		}
		ptr++;
	}
	
	for (i = 0; i < SIZE; i++)
		printf("%d ", input[i]);
	

	return 0;

}
