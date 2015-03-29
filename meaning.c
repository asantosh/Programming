#include <stdio.h>
#include <string.h>

int get_string(char *ip, char (*op)[49])
{
    int n , i, j;
    char *c;
    n = strlen(ip);
    printf("%s %d \n",ip ,n);

    for(i=0; i<n; i++)
    {
	c = ip;
	for(j=0; j<n; j++, c++)
	{
	    if(j == i)
		c++;
	    op[i][j] = *c;
	}
	printf("%s\n",op[i]);
    }

    return 0;
}


int main(int argc, char *argv[])
{
    char a[50] = {0};
    char b[50][49] = {{0}};

    if(argc != 2) {
	printf("Error\n");
	return 1;
    }

    strcpy(a, argv[1]);
    printf("%s \n",a);
    get_string(a, b);

    return 0;

}






