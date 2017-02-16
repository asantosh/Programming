#include <stdio.h>
#include "libgsh.h"

int test_val;

int print_val(void)
{
    printf("%s: %d\n", __func__, test_val);
    return 0;
}
