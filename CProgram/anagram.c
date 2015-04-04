#include <stdio.h>
#include <string.h>

#define MAX 9

int main()
{
    char ip[][10]= {"tar","bca","acb","rat","rat","abc","cba","banana","atr"};
    char temp[10] = {0};
    int i, j, tmp=0;
    int val[MAX] = {0};

    for(i = 0; i< MAX ; i++)
    {
	for(j=0; ip[i][j] != '\0' ; j++)
	    val[i] += j*ip[i][j];
    }

    for(i = 0; i < MAX-1; i++)
    {
	for(j = 0; j < MAX-i-1; j++)
	{
	    if(val[j] > val[j+1]) {
		tmp = val[j];
		val[j] = val[j+1];
		val[j+1] = tmp;
		strcpy( temp ,  ip[j]  );
		strcpy( ip[j],  ip[j+1]);
		strcpy( ip[j+1],temp   );
	    }
	}
    }

    for(i = 0; i< MAX ; i++)
	printf("%d %s  \n",val[i], ip[i]);

    return 0;
}

