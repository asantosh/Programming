#include <stdio.h>

int main(void)
{
    int mat[3][3] = {0};
    int i;

    for(i = 0; i< 9; i++) {
	*mat[i] = i;
	printf("i = %d \t mat = %d\n", i, *mat[i]);
    }

    return 0;


}
