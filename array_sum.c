#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int arr[] = {0,1,1,1,2,3,3,3,4,4,5,6,7,8,8,8,9,10,11,12};
	int num = 0;
	int *sptr = NULL, *nptr = NULL;
	int sum = -1;

	if (argc != 2){
		printf("Invalid Input\n");
		return -1;
	}
	sum = atoi(argv[1]);
	
	num = sizeof(arr)/sizeof(arr[0]);
	sptr = arr;
	nptr = arr+num-1;

	while (sptr < nptr) {
		num = *sptr + *nptr;
		if (num < sum)
			sptr++;
		else if (num > sum)
			nptr--;
		else
			printf(" %d + %d = %d\n", *sptr++, *nptr--, sum);
	}

	return 0;
}

	


