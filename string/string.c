#include <stdio.h>
#include <stdlib.h>

char *my_strncpy(char *dst, const char *src, size_t n)
{
	char *res = dst;

	if(dst == NULL || src == NULL)
		return dst;
	
	while(n-- > 0 && *src != '\0')
		*dst++ = *src++;
	
	*dst = '\0';

	return res;
}

char *my_strcpy(char *dst, const char *src)
{
	char *res = dst;
	
	if(dst == NULL || src == NULL)
		return dst;

	while(*dst++ = *src++)
		;

	return res;
}

size_t my_strlen(const char *str)
{
	int rc = 0;

	if(str == NULL)
		return rc;

	while (*str++)
		rc++;

	return rc;
}

int my_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0') {
		if (*s1++ != *s2++) 
			break;
	}

	return *s1 - *s2;
}

int my_strncmp(char *s1, char *s2, size_t n)
{
	while (n-- > 0 && *s1 != '\0') {
		if (*s1++ != *s2++)
			break;
	}

	return *s1 - *s2;
}

char *my_strstr(char *str, char *sub_str)
{
	unsigned int i, j, found = 1;

	for (i = 0; *(str+i) != '\0'; i++) {
		found = 1;
		for (j = 0; *(sub_str+j) != '\0'; j++) {
			if (*(sub_str+j) != *(str+i+j)) {
				found = 0;
				break;
			}
		}

		if (found)
			return str+i;
	}

	return NULL;
}

int my_touppper(char c)
{
	if (c >= 'a' && c <= 'z')
		return c-'a'+'A';
	else 
		return c;
}

int my_tolower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return c-'A'+'a';
	else 
		return c;
}

int main(void)
{
	char *src = "hello world    asd 987 j#$$$$$";
	char *dst;
	
	dst = (char *)malloc(my_strlen(src)+1);
	if (dst == NULL)
		return -1;

	printf("\nsrc = %s\n", src);
	printf("\nstrcpy = %s\n", my_strcpy(dst, src));
	printf("\nstrncpy = %s\n", my_strncpy(dst, src, 10));
	printf("\nstrcmp = %d\n", my_strcmp(dst,src));
	printf("\nstrncmp = %d\n", my_strncmp(src, dst, 9));

	printf("\nstrstr = %s\n", my_strstr(src, "wtrld"));

	free(dst);

	printf("%c\n", my_touppper('1'));
	printf("%c\n", my_tolower('a'));
	return 0;
}
