#include <stdio.h>
#include <stdlib.h>

void foo(char **c)
{
    char *t = (char *) malloc(5);

    t = "hell";

    printf("t = %s\n", t);

    *c = t;

    return;
}


int main(void)
{
    char *a = NULL;

    foo(&a);

    printf("a = %s\n", a);

    return 0;
}
