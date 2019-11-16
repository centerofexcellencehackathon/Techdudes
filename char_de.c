#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(void)
{
	int hours, minutes, seconds, day, month, year,x,y,t;
	signed char i,e,d;

	printf("enter the encrypted character\n");
	scanf("%c",&e);

	printf("hours=");
	scanf("%d",&hours);
	
	printf("\nminutes=");
	scanf("%d",&minutes);

	
	printf("\nseconds=");
	scanf("%d",&seconds);

	
	printf("\ndate=");
	scanf("%d",&day);

	printf("\nmonth=");
	scanf("%d",&month);


	if(seconds>minutes)
		x=((seconds*2)-(minutes*2))+(month-4);
	else
		x=((minutes*2)-(seconds*2))+(month-4);
	
	y=((hours*seconds)/12)-day;
	
	if(x>y)
	t=x-y;
	else
	t=y-x;
	
	d=e+t;

		printf("the decrypted character is:%c\n\n",d);
}

