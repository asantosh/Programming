#include <stdio.h>

int main(void)
{
    long long num;

    scanf("%lld", &num);

    if(num < 0)
	return 0;

    if (num % 6 == 0 || (num-1) % 6 == 0 || (num-3) % 6 ==0)
	printf("yes\n");
    else
	printf("no\n");


    return 0;
}
