#include <stdio.h>

int get_sum(int m, int n, int *arr)
{
    int i,sum = 0;
    for (i = m; i <= n; i++)
	sum += arr[i];

    return sum;
}

int main()
{
    int a[] = {2,3,4,5,6};
    int b[] = {1,2,3,8,1};
    int i , j, i_max, j_max, sum_a, sum_b, num;

    i = j = i_max = j_max = sum_a = sum_b = 0;
    num = sizeof(a)/sizeof(a[0]);

    for (i=0; i<num; i++)	
	for (j=i+1; j<num; j++) {
	    if (get_sum (i,j,a) == get_sum (i,j,b)) {
		if ((j - i) > (j_max - i_max)) {
		    i_max = i;
		    j_max = j;
		}
	    }
	}

    printf("\ni = %d j = %d \n", i_max+1, j_max+1);

    getchar();
    return 0;
}


