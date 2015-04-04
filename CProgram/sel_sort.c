#include <stdio.h>

#define len(array) sizeof(array)/sizeof(array[0])

main()
{
    int arr[]={0,1,54,6,7,5,34,67,8,5,56,34,2,3,4,55,6,8,9};
    int pt1 = 0, pt2=0, temp=0;

    for(pt1=0; pt1< len(arr)-1 ; pt1++)
    {
	for(pt2=pt1; pt2 < len(arr); pt2++)
	{
	    if(arr[pt1] > arr[pt2])
	    {
		temp = arr[pt1];
		arr[pt1] = arr[pt2];
		arr[pt2] = temp;
	    }
	}
    }

    for(pt1=0; pt1< len(arr) ; pt1++)
	printf("%d\n", arr[pt1]);

}
