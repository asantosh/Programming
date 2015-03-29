#include <stdio.h>

void fun1(void)
{
    static int a = 5;
    printf("%d\n", a);
}

void fun2(void)
{
    static int a = 6;
    printf("%d\n", a);
}

int main(void)
{
    fun1();
    fun2();

    return 0;
}
