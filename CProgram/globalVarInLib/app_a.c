#include "libgsh.h"

int main(void)
{
    test_val = 0;
    while (1) {
        test_val += 2;
        printf("A: %s :%d\n", __func__, test_val);
        printf("From A:");
        print_val();
        sleep (3);
    }
    return 0;
}
