/*test.c : File to test the basic malloc feature implemented using m_malloc

To build:
 	For linux : gcc -Wall test.c malloc.c -o test
*/

#include <stdio.h>
#include "malloc.h"

/*Set the number of bytes*/
#define MAX_B 4

int main(void)
{
	int *ptr;
	int cnt;

	/*Allocate 4 bytes*/
	ptr = m_malloc(MAX_B);
	if (!ptr) {
		printf("Error: Unable to allocate memory\n");
		return -1;
	}
	
	for (cnt = 0; cnt < MAX_B; cnt++) {
		ptr[cnt] = cnt;
		printf("Value ptr[%d] = %d\n", cnt, ptr[cnt]);
	}

	return 0;
}
