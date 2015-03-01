#include <stdio.h>

#define debug(fmt, ...) printf("DEBUG %s:%d: "fmt , __func__, __LINE__, ##__VA_ARGS__)


int main(void)
{
	debug("hello \n");

	return 0;
}
