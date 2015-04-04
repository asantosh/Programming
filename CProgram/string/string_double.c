#include <stdio.h>

int foo(char **sr)
{

    printf("sr = %s \n", *sr);

    **sr = 'y';
    *(++(*sr)) = 'm';

    printf("sr = %s \n", *sr);

    return 0;

}

int main()
{
    char string[5] = "hello", *str = string;

    printf("string = %s,  str = %s\n", string, str);

    foo(&str);

    printf("string = %s,  str = %s\n", string, str);

    return 0;
}
