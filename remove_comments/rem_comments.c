#include <stdio.h>
#include <errno.h>
#include <string.h>

#define MAX_SIZE 80
#define EXIT_SUCCESS 1
#define EXIT_FAILURE 0

#define FOUND 	1
#define N_FOUND 0

#define LINE 		0
#define BLOCKSTART 	1

static int status = FOUND;


int comment(char **str, int type)
{
	*((*str)++) = '\n';
	*((*str)++) = '\0';

	switch (type) {
		case LINE:
			break;

		case BLOCKSTART:
			while (*((*str)++) != '\0') {
				if (**str == '*' && *(*str+1) == '/') {
					status = FOUND;
					break;
				}
				else
					status = N_FOUND;
			}
			break;

		default:
			return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

int remove_comment(char *inFile, char *outFile)
{
	FILE *inFp, *outFp;
	char string[MAX_SIZE], *stringPtr;

	inFp = fopen(inFile, "r");
	if (inFp == NULL)
		goto err1;

	outFp = fopen(outFile,"w");
	if (outFp == NULL)
		goto err2;

	while (fgets(string, sizeof(string), inFp) != NULL) {
		stringPtr = string;	

		while (*stringPtr != '\0') {
			if (!status){
				while (*stringPtr != '\0') {
					if (*stringPtr == '*' && *(stringPtr+1) == '/') {
						status = FOUND;
						break;
					}
					stringPtr++;
				}
				string[0] = '\n';
				string[1] = '\0';
			} else {
				if (*stringPtr == '/' && *(stringPtr+1) == '/')
					comment(&stringPtr, LINE);

				else if (*stringPtr == '/' && *(stringPtr+1) == '*')
					comment(&stringPtr, BLOCKSTART);
			}

			if (!status)
				break;

			stringPtr++;
		}
		fputs(string, outFp);
	}

	fclose(inFp);
	fclose(outFp);

	return EXIT_SUCCESS;

err2:
	fclose(inFp);

err1:	
	printf("Error: %s\n", strerror(errno));

	return EXIT_FAILURE;

}

int fileCopy(char *infile, char *outfile)
{
	FILE *inFp, *outFp;
	char ch;

	inFp = fopen(infile, "r");
	if (inFp == NULL)
		goto err1;
	
	outFp = fopen(outfile,"w");
	if (outFp == NULL)
		goto err2;

	do {
		ch = fgetc(inFp);
		fputc(ch,outFp);
	} while(ch!=EOF);	
	
	fclose(inFp);
	fclose(outFp);

	return EXIT_SUCCESS;

err2:
	fclose(inFp);
err1:	
	printf("Error: %s\n", strerror(errno));

	return EXIT_FAILURE;
}


int main(int argc, char* argv[])
{
	char *inFile, *outFile;

	if (argc < 3) {
		printf(" Invalid input \n Expected: \"com <in file name> <out file name>\" \n");
		return EINVAL;
	}
	
	inFile = argv[1];
	outFile = argv[2];

	if (remove_comment(inFile, outFile))
		printf("Removed // comment, check output file\n");
	else
		printf("Error removing comment\n");

	return 0;
}
