#include <stdio.h>
#include <stdlib.h>

/*stack size*/
#define SIZE 32

typedef struct node {
	size_t data;
	struct node *prev;
}stack;

static stack *sp = NULL;
unsigned short size = SIZE;

char is_empty(void)
{
	return sp == NULL ? 1 : 0;
}


void push(size_t num)
{
	stack *tmp = (stack *)malloc(sizeof(stack));

	if(size == 0) {
		printf("Stack Overflow\n");
		return;
	}

	size--;
	tmp->data = num;

	if (is_empty()) {
		tmp->prev = NULL;
		sp = tmp;
	} else {
		tmp->prev = sp;
	}
	
	sp = tmp;

	return;
}

void pop(void)
{
	stack *tmp = sp;
	
	if (is_empty()) {
		printf("empty\n");
		return;
	}
	
	size++;
	printf("pop - %d\n", sp->data);
	sp = sp->prev;
	
	free(tmp);
	
	return;
}

int main(void)
{
	unsigned short count = 0;


	printf("size : %d\n", size);

	for (count = 0; count < 32; count++)
		push(count);

	for (count = 0; count < 32; count++)
		pop();
	
	printf("size : %d\n", size);
	return 0;
}
