#include <stdio.h>

main(){
    const int ci = 123;
    int *ncpi;

    ncpi = &ci;

    printf("Before: ci = %d\n",ci);

    *ncpi = 0;

    printf("After: ci = %d\n",ci);
}
