/*malloc.c
Function malloc() is a basic function that allocates memory using sbrk system call
This does not support free() or realloc()

calloc() is similar to malloc, except that it sets values in the memory location to zero
*/

/* HEAP SECTION
-----------------------------------------------------
|					|								|		
|sLimit				|<-break					rLimit  |
|(mapped region)    |			(unmapped region)	|
-----------------------------------------------------
*/

#include <stdio.h>          //NULL 
#include <sys/types.h>      //size_t
#include <unistd.h>			//sbrk
#include "malloc.h"

void *m_malloc(size_t size)
{
	void *ptr = NULL;

	/*Get the current break location from the heap*/
	ptr = sbrk(0);
	/*sbrk would move the break to the location specified by size*/
	sbrk(size);

	return ptr;
}

void *m_calloc(size_t size)
{
	void *ptr;
	char *chptr = NULL;
	size_t count;

	ptr = m_malloc(size);

	if (!ptr)
		return ptr;

	chptr = ptr;
	for (count = 0; count < size; count++)
		*chptr++ = 0;

	return ptr;
}
