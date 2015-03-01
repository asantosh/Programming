#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <malloc.h>

int main(void)
{
	int *sptr = (int *) sbrk(0);
	int *ptr  = (int *) malloc(15);
	int *eptr = (int *) sbrk(0);

	printf("start sptr = %p\n", sptr);

	printf("before heap mem = %d\n", eptr - sptr);
	
	ptr  = (int *) malloc(15);
	eptr = sbrk(0);

	printf("after heap mem = %d\n", eptr - sptr);
	
	printf("Alloc mem = %d\n", malloc_usable_size(ptr));
	free(ptr);

	eptr = sbrk(0);
	printf("end end = %p\n", eptr);

	return 0;
}

