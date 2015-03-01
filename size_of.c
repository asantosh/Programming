#include <stdio.h>

struct ele {
	int i;
	char c;
};

int main(void)
{
	int *i = 0;
	char *c = 0;
	struct ele *new;
	int size = 0;

	//size = (int)new - (int)++new;
	//size = (int)c - (int)++c;
	size = (int)i - (int)++i;

	printf("sizeof = %d pointer = %d\n", sizeof(int), -size);
	
	return 0;
} 
