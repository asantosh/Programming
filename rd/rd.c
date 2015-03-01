#include <stdio.h>

void cal_rd(int month, float deposit, float rate )
{
	printf("in cal_rd\n");
	float interest = (deposit * month * rate / 100);
//	cal_rd	
	printf("Interest = %f, total = %f \n",interest, (interest + deposit));
}


int main(int argc, char argv[])
{
	int month;
	float deposit;
	float rate;
	
	if(argc != 4)
	{
		printf("invalid input\n");
		return 0;
	}
	
	month 	= atoi(argv[1]);
	deposit = atof(argv[2]);
	rate 	= atof(argv[3]);
	if(month <=0 || deposit <=0)
	{
		printf("invalid input\n");
		return 0;
	}

	cal_rd(month, deposit, rate);

	return 0;
}
