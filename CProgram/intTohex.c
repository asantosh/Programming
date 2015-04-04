#include <stdio.h>

/*find the string length*/
int strglen(char *str)
{
    int len = 0;

    if (str == NULL)
	return len;

    while(*str++ != '\0')
	len++;

    return len;
}

/*string to integer*/
int stoi(char *str)
{
    int len = 0;
    int count = 0;
    int sum = 0;

    len = strglen(str);

    for	(count = 0; count < len; count++) {
	if (str[count] < '0' || str[count] > '9')
	    break;
	sum = sum *10 + str[count] - '0';
    }

    return sum;
}

void printHex(int num)
{
    int tmp = 0;
    char c[10] = {0};
    int i = 0;

    while (num > 0) {
	tmp = num % 16;
	if (tmp <= 9) {
	    c[i] = tmp + '0';
	    //printf("%d", tmp);
	}else {
	    tmp = tmp - 10 + 'A';
	    c[i] = tmp;
	    //printf("%c", tmp);
	}
	num /= 16;
	i++;
    }

    printf("0x");
    while (i-- > 0)
	printf("%c", c[i]);

    printf("\n");
}


/*main*/
int main(int argc, char *argv[])
{
    int num;

    if (argc  != 2)
	return -1;

    num = stoi(argv[1]);

    printf("num = %x \n", num);
    printf("num in hex  = ");
    printHex(num);

    return 0;
}
