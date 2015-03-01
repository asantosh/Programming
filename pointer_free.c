#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *ptr = malloc(sizeof(int));

	*ptr = 8;

	printf("%p %d\n", ptr, *ptr);

	free(ptr);
	
	printf("%p %d\n", ptr, *ptr);
	
	free(ptr);

	return 0;
}
