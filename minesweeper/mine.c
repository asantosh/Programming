#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define block	5
#define mines	10

int get_rand(void)
{
	return rand() % block;
}

int display(int mat[][block])
{
	int row, col;
	
	for (row = 0; row < block; row++) {
		for (col = 0; col < block; col++) {
			if (mat[row][col] == -1)
				printf("x  ");
			else if (mat[row][col] == -2)
				printf("-  ");
			else
				printf("%d  ", mat[row][col]);
		}
		printf("\n");
	}
	printf("\n");
	
	return 0;
}

int set_mine(int mat[][block])
{
	int row = -1, col = -1, count;
		
	for (count = 0; count < mines; count++) {
		row = get_rand();
		col = get_rand();
		mat[row][col] = -1 ;

		if (row - 1 >= 0) {
			if (mat[row - 1][col] != -1)
				mat[row - 1][col] 	+= 1;
			
			if (col - 1 >= 0 && mat[row - 1][col-1] != -1)
				mat[row - 1][col-1] += 1;
			if (col + 1 < block && mat[row - 1][col+1] != -1)
				mat[row - 1][col+1] += 1;
		}
		
		if (col - 1 >= 0 && mat[row][col-1] != -1)
			mat[row][col-1] += 1;
		
		if (col + 1 < block && mat[row][col+1] != -1)
			mat[row][col+1] += 1;
		
		if (row + 1 < block) {
			if (mat[row + 1][col] != -1)
				mat[row + 1][col] 	+= 1;
			if (col - 1 >= 0 && mat[row + 1][col-1] != -1)
				mat[row + 1][col-1] += 1;
			if (col + 1 < block && mat[row + 1][col+1] != -1)
				mat[row + 1][col+1] += 1;
		}
	}
	return 0;
}
int main(void)
{
	time_t t;
	int matrix[block][block],  output[block][block];
	int  status = 0, row, col, count = 0;
	char c;
	srand((unsigned int)&t);
	
	memset(matrix, 0, sizeof(matrix));
	for (row = 0; row < block; row++)
		for (col = 0; col < block; col++)
			output[row][col] = -2;
	

	set_mine(matrix);
	display(matrix);
	
	while (!status && count < 9) {
		scanf(" %c %d %d", &c, &row, &col);
		count++;
		switch (c) {
			case 'd' :
			case 'D' :
					if (matrix[row][col] == -1)
						status = 1;
					else {
						output[row][col] = matrix[row][col];
						display(output);
					}
					break;
					
			
			case 'm' :
			case 'M' :
					if (matrix[row][col] != -1)
						status = 1;
					else {
						output[row][col] = -1;
						display(output);
					}
					break;
			default:
					count--;
					printf("Invalid Input\n");
					break;			
		}
		if(status == 1) {
			printf("Game OVer\n");
			break;
		}
	}
	
	if(status == 2)
			printf("You won\n");

	return 0;
}