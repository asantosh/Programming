#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char input[] = "hello world hello santosh new august world san santosh hello helo";
    char *test ;
    char *check[10] ;
    int flag = 0 ,indexRow, indexCol, count = 0 ;

    test = strtok(input," ");

    for(indexRow = 0; test != NULL; indexRow++) {
	check[indexRow] = test ;
	test = strtok(NULL, " ");
    }
    count = indexRow;

    for(indexRow = 0; indexRow < count; indexRow++) {
	for(indexCol = 0; indexCol < indexRow; indexCol++) {
	    if (!strcmp (check[indexRow],check[indexCol]))
		flag = 1;
	}
	if(!flag)
	    printf("%s ",check[indexRow]);
	flag = 0;

    }

    getchar();
    return 0;
}
