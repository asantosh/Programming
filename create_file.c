#include <stdio.h>
#include <stdlib.h>

/*File size to be created in KB, MB minimum 4k */
#define FS_K(x) 	x * 1024
#define FS_M(x) 	FS_K(x) * 1024

int main(int argc, char *argv[])
{
    FILE *fp;
    int i = 0;
    unsigned int size = atoi(argv[1]);

    fp = fopen("test_file.txt", "w");

    for (i=0; i < FS_M(size) ; i++) 
	fprintf(fp, argv[2]);

    fclose(fp);

    return 0;
}
