#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if(argc != 2)
	return 1;

    int x = atoi(argv[1]);
    int ans = -1;

    ans = x % 2 != 0 ? 0: (x-1) / 2 ;

    printf("%d\n", ans);


    return 0;
}
