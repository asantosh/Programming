#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int x;
    x = (float) 7/5;

    char a[]="3.14"; 
    printf("a = %s \n",a);
    //	x = atoi(a);
    printf("x = %.2d \n",x);

    return 0;
}
