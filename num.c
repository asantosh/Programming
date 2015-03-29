#include <stdio.h>
#include <stdlib.h>

#define max 100

int main(int argc, char *argv[])
{
    int val[max] = {0};
    int i = 0, count;
    int num, *tptr;

    FILE *fs = fopen("file.txt", "r");

    while (i < max) {
	num = fread((int*)tptr, sizeof(val), 1, fs);
	if(num > 0) {
	    i++;
	    val[i] = *tptr;
	}
	else 
	    break;
    }

    count = i;

    for(i=0; i< count; i++)
	printf("%d ",val[i]);

    return 0;
}


