#include <stdio.h>
#include <string.h>

void func(char *input)
{
    char string[5] = {0};

    printf("Before: string = %s \n", string); 

    strcpy(string, input);

    printf("After: string = %s \n", string);

}

int main(void)
{
    char *str = "helloworld";

    printf("str = %s \n", str);

    func(str);

    return 0;
}
