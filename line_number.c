#include<stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *fp_in = NULL;
	char string[80];

	fp_in = fopen("name.txt","w+");
	fp_out = fopen("name_line.txt", "w+");
	
	if (fp_in == NULL|| fp_out == NULL) {
		printf("Failed to open file!");
		return -1;
	}

	fscanf(fp_in, "%s", &string);
//	while (string != NULL) {
		printf("%s\n", string);
		fscanf(fp_in, "%s", string);
//		fprintf(fp_out,"(%d) %s",counter,string);

		counter++;
//	}
	
	printf("All done!");
	fclose(fp_in);
	fclose(fp_out);

	return 0;

}
