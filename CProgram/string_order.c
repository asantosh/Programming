#include <stdio.h>
#include <string.h>

int main(void)
{
    char input1[] = "Keep rocking as always";
    char *input = input1;
    char output[14] = {0};
    int len = 0;
    char *temp_ptr = NULL;
    int count = 0;

    while(input != NULL)
    {
	if(*input == ' ')
	{
	    input++;
	    strcpy(output, input);
	    temp_ptr = output;
	    count = strlen(input) - len;
	    for(; count != 0; count--)
		temp_ptr++;
	    /* TODO */
	    strcat(temp_ptr, );

	    len = 0;

	}
	input++;
	len++;
    }		
    return 0;
}


