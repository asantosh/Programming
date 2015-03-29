#include <stdio.h>
#include <stdlib.h>

void fun2(int *t)
{
    printf("t = %p\n", t);
    //	free(t);
    //	t = NULL;
}

void fun1(int **q)
{
    printf("*q = %p\n", *q);
    fun2(*q);
    //	*q = NULL;
}


int main(void)
{
    int *p = (int *)malloc(2);

    printf("p = %p\n", p);
    fun1(&p);
    p = NULL;
    printf("p = %p\n", p);

    if (p)
	printf("fail\n");
    else
	printf("done\n");

    getchar();

    return 0;
}
