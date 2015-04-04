#include <stdio.h>
#include <netdb.h>
#include <string.h>

int main(int argc, char *argv[])
{
    struct hostent *hp ;
    char input[25]={0};

    if(argc !=2)
	return 1;

    strcpy(input, argv[1]);
    hp = gethostbyname(input);

    if ( hp == NULL )
    {
	printf("Unknown host or Network down %s \n", hp->h_name);
	return 1;
    }
    printf("Network UP %s \n", hp->h_name);

    return 0;
}
