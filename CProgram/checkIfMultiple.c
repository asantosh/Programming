#include <stdio.h>

#define TEST_LIMIT 1024
#define check_mul_32(x) (!(x & 0x1f))
#define check_mul_64(x) (!(x & 0x3f))
#define check_mul_128(x) (!(x & 0x7f))
#define check_mul_256(x) (!(x & 0xff))

int main(void)
{
    int i;

    for (i = 1; i < TEST_LIMIT; i++)
        if (check_mul_32(i))
            printf("32 x %d = %d\n", i/32, i);

    printf("\n----------------------------\n");

    for (i = 1; i < TEST_LIMIT; i++)
        if (check_mul_64(i))
            printf("64 x %d = %d\n", i/64, i);
    printf("\n----------------------------\n");

    for (i = 1; i < TEST_LIMIT; i++)
        if (check_mul_128(i))
            printf("128 x %d = %d\n", i/128, i);
    printf("\n----------------------------\n");

    for (i = 1; i < TEST_LIMIT; i++)
        if (check_mul_256(i))
            printf("256 x %d = %d\n", i/256, i);

    return 0;
}
