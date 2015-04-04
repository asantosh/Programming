#include <stdio.h>

int main(void)
{
    int arr[] = {1,2,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int index = 0;

    for	(index = 0; index < n; index++)
	printf("%d \n", arr[index]);


    return 0;

}
