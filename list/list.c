#include <stdio.h>

struct node{
	int num;
	struct node *nptr;
};

typedef struct node list;
typedef list *listptr;

listptr cptr, head, ptr, sptr;

int isempty(listptr ptr);
listptr insert(listptr ptr,int data );
void delete(listptr startptr , int data);
void printlist(listptr startptr);


int main(int argc , char *argv[]) {

	int i = 0;

	sptr = (listptr) malloc(sizeof(list));
	head = sptr;
	cptr = sptr;

	for(i =1; i<=4 ; i++) {
		cptr = insert(cptr, i);
	}
	printlist(sptr);
	delete(sptr, 3);
} 

listptr insert(listptr ptr,int data )
{
	cptr = ptr;
	cptr->num = data;
	cptr->nptr = (listptr)malloc(sizeof(list));
	cptr = cptr->nptr;

	return cptr;
}

void delete(listptr startptr, int data)
{
	cptr = startptr;  
	if(startptr->num ==data) {
		sptr = cptr->nptr; 
		cptr = cptr->nptr ;
	}
	else {	 
		while (cptr != NULL) {
			if(cptr->num == data) {
				(--cptr)->nptr = cptr->nptr->nptr;
				free(cptr); 
			}
		}
	}
}
void printlist(list *sptr) {
	while (sptr != NULL) {
		printf ("\n data = %d \t nptr = %d \n", sptr->num, sptr->nptr);
		sptr = sptr->nptr; 
	}
}  

