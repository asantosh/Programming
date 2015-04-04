#include <stdio.h>

int main()
{
    char *str = "hello world you are great";
    char *sub_str = "you";
    char *str_tmp = NULL;
    char *sub_str_tmp = NULL;
    int found = 1;

    while (str++ != NULL) {
	str_tmp = str;
	sub_str_tmp = sub_str;
	printf("%s\n", str_tmp);
	while (sub_str_tmp != NULL) {

	    printf("%s\t", str_tmp);
	    printf("%s\n", sub_str_tmp);

	    if (sub_str_tmp++ != str_tmp++) {
		found = 0;
		break;
	    }
	}
	if (found)
	    printf("found @ %s \n", str);
	found = 1;
    }

    return 0;
}
