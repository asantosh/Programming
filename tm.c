#include <stdio.h>

void print(int *); 

void main()
{
	int *ptr1=0,*ptr2=0; 
	print(ptr1,ptr2); 
} 

void print(int *a,int *b)
{ 
	printf("\na=%d\tb=%d",a,b); 
}
