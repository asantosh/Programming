/*test.c : File to test the basic malloc feature implemented using m_malloc

  To build:
  For linux : gcc -Wall test.c malloc.c -o test
 */

#include <stdio.h>
#include "malloc.h"

/*Set the number of bytes*/
#define MAX_B 4
#define MEM   4		/*number of members*/

int main(void)
{
    int *ptr;
    int cnt;

    /*Allocate 4 bytes*/
    printf("MALLOC\n");
    ptr = m_malloc(MAX_B);
    if (!ptr) {
	printf("Error: Unable to allocate memory\n");
	return -1;
    }

    *ptr = MAX_B;
    printf("Value of ptr = %p, *ptr = %d\n", ptr, *ptr);

    m_free(ptr);

    printf("\nCALLOC\n");
    ptr = m_calloc(MEM, MAX_B);
    if (!ptr) {
	printf("Error: Unable to allocate memory\n");
	return -1;
    }

    for (cnt = 0; cnt < MEM; cnt++)
	printf("Value of ptr = %p and *ptr = %d\n", &ptr[cnt], ptr[cnt]);

    m_free(ptr);

    return 0;
}
