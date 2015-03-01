#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	char *src = "hello";
	char *dst = (char *)malloc(6);
	char *dst_l = (char *)malloc(4);
	char *dst_g = (char *)malloc(10);

//	printf("strcpy %s\n", strcpy(dst,NULL));

	printf("strcpy %s\n", strcpy(dst,src));
	printf("strcpy_l %s\n", strcpy(dst_l,src));
	printf("strcpy_g %s\n", strcpy(dst_g,src));
	
	printf("strncpy %s\n", strncpy(dst,src, 4));
	printf("strncpy_l %s\n", strncpy(dst_l,src, 6));
	printf("strncpy_g %s\n", strncpy(dst_g,src, 20));

	printf("strstrc %s\n", strstr(src, "thel"));

	free(dst);
	free(dst_l);
	free(dst_g);


	return 0;
}
