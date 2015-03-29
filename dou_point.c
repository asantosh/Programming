#include <stdio.h>

int main()
{
    char **p;
    int *t;
    char a[]="hello";
    t = a;
    p = &t;

    printf("%c\n",*t);
    printf("%c\n",**p);
    printf("%p\n",*a);
    printf("%x\n",'h');

    return 0;
}

