#include <stdio.h>

#define M 3

void print(int mat[M][M])
{
	int row, col;

	for (row = 0; row < M; row++) {
		for (col = 0; col < M; col++) {
			printf("%d ", mat[row][col]);
		}
		printf("\n");
	}
	printf("\n");
}

void rotate90(int mat[M][M], int res[M][M])
{
	int row, col;
	
	for (row = 0; row < M; row++)
		for (col = 0; col < M; col++)
			res[col][M-row-1] = mat[row][col];

}

int main(void)
{
	int arr[M][M] = { {1,2,3}, {4,5,6}, {7,8,9} };
	int out[M][M];
	
	print(arr);

	rotate90(arr, out);

	print(out);
	
	return 0;
}

