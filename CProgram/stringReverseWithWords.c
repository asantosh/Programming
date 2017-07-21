#include <stdio.h>
#include <string.h>

void reverseString(char *str, int len)
{
    char *sptr = str;
    char *eptr = str+len-1;
    char tmp;

    while (sptr < eptr) {
        tmp = *sptr;
        *sptr++ = *eptr;
        *eptr-- = tmp;
    }
    return;
}

int reverseLine(char *str)
{
    int i, proc_len = 0;
    int len = strlen(str);
   
    if (!str)
        return -1;

    reverseString(str, len);

    for (i = 0; i < len; i++) {
        if (*(str+i) == ' ') {
            reverseString(str+i-proc_len, proc_len);
            proc_len = 0;
            i++;
        }
        proc_len++;
    }

    reverseString(str+len-proc_len, proc_len);
    return 0;
}

int main(int argc, char* argv[])
{
    char *i_str;

    if (argc != 2) {
        printf("Invalid input\n");
        return -1;
    }

    i_str = argv[1];

    printf("Input: %s\n", i_str);
    reverseLine(i_str);
    printf("Output: %s\n", i_str);

    return 0;
}
