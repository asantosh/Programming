#include <stdio.h>
#include <stdlib.h>

#if 0
void function(int array[]){

    array[0] = 4;
    array[1] = 5;
    array[2] = 6;
	*(array+1) = 10;   
}

int main(){

    int array[] = {1,2,3};
    function(array);
    printf("%d %d %d\n",array[0],array[1],array[2]);
    return 0;
}
#endif

int main(void)
{
	int *ptr = NULL;
	int cnt = 0;
	
	ptr = malloc(20*4);		// 20 locations
	if (ptr == NULL)
		goto err;
		
	for(cnt = 0; cnt < 20; cnt++) {
		*(ptr + cnt) = malloc(1);
		if (*(ptr + cnt) == NULL)
			goto err;
	}

	printf("Mem allocated\n");
	
	for(cnt = 0; cnt < 20; cnt++)
		free(*(ptr+cnt));
	
	free(ptr);
	ptr = NULL;

	printf("Mem deallocated\n");

	return 0;
err:
	printf("Mem allocation failed\n");
	return -1;
}
