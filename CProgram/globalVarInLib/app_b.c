#include "libgsh.h"

int main(void)
{
    test_val = 0;
    while (1) {
        test_val += 5;
        printf("B: %s :%d\n", __func__, test_val);
        printf("From B:");
        print_val();
        sleep (3);
    }
    return 0;
}
