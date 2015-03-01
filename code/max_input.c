#include <stdio.h>
   
#define SIZE 131070

int main(void)
{
	long n, k, input = 0, index = 0, count = 0, len = 0;
	char buffer[SIZE];
	int tmp;

	scanf("%ld %ld", &n, &k);

	while ((len = fread(buffer, sizeof(char), SIZE, stdin)) > 0)
	{
		for (index = 0; index < len; index++)
		{
			tmp = buffer[index];
			if (tmp == '\n')
			{
				if (input % k == 0) 
					count++;
				input = 0;
			}
			else
				input = (input * 10) + (tmp - '0');
		}

	}

	printf("%ld\n", count);
	return 0;
}
