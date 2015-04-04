#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
    int i = atoi(argv[1]);

    if(i > 5){
	if((i -1) % 8 == 0) i=1;
	else if(i % 2 == 0) {
	    while(i > 5) {
		i -= 2;
		i -= 6;
	    }
	    if( i == -2) i = 4;
	    if( i == 0) i = 2;
	}
	else if((i+1) % 4 == 0) i=3;
	else i=5;
    }		
    printf("%d \n", i);
    return 0;
}
