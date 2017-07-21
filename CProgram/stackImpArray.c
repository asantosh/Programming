#include <stdio.h>

#define STACK_LIMIT 128

int stk[128], sp = -1;

int s_push(int val)
{
    if (sp++ > STACK_LIMIT) {
        printf("PUSH: Stack full\n");
        return -1;
    }
    
    stk[sp] = val;
    return 0;
}

int s_pop(int *val)
{
    if (sp < 0) {
        printf("POP: Stack Empty\n");
        return -1;
    }
    
    *val = stk[sp--];
    return 0;
}

int main(void)
{
    int i, val;

    for (i = 0; i < STACK_LIMIT; i+=2)
        s_push(i);

    for (i = 0; i < STACK_LIMIT; i++) {
        if(s_pop(&val) == 0)
            printf("POP: %d\n", val);
    }

    return 0;
}
