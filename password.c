#include <stdio.h>
#include <string.h>

int checkPassword(char *password)
{

	char passwd[10];

	memset(passwd, 0, 10);

	strcpy(passwd, password)

	if ( 0 == strcmp("LinuxGeek", passwd))
		return 1;

	return 0;
}

int main(int argc, char*argv[])
{
	char *str;

	str = argv[1];

	if (checkPassword(str))
		printf("found \n");
	else
		printf("Not found \n");

	memset(passwd, 0, 10;
	return 0;
}
