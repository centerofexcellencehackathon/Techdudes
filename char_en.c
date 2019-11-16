#include<stdio.h>
#include <stdlib.h>
#include <time.h>


int main(void)
{
	int hours, minutes, seconds, day, month, year,x,y,t;
	signed char i,e,d;
	time_t now;
	time(&now);
	
	struct tm *local = localtime(&now);

	hours = local->tm_hour;			
	minutes = local->tm_min;		
	seconds = local->tm_sec;		

	day = local->tm_mday;			
	month = local->tm_mon + 1;		
	year = local->tm_year + 1900;	

	printf("enter any character\n");
	scanf("%c",&i);


	if(seconds>minutes)
		x=((seconds*2)-(minutes*2))+(month-4);
	else
		x=((minutes*2)-(seconds*2))+(month-4);
	
	y=((hours*seconds)/12)-day;
	

	if(x>y)
	t=x-y;
	else
	t=y-x;
	
	e=i-t;

	printf("the encrypted character is:%c\n\n",e);
	printf("\n hour=%d\nminute=%d\nsecond=%d\ndate=%d\nmonth=%d\n",hours, minutes, seconds, day, month);
}
	
