//encryption and decryption of a string WITHOUT date and time AS INPUT
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<string.h>

int hours,minutes,seconds,day,month,x,y,t=0;
int encrypt(int);
int decrypt(int);

int main()
{
    int a,ch;
    time_t now;
    time(&now);

    struct tm *local = localtime(&now);
    hours = local->tm_hour;
    minutes = local->tm_min;
    seconds = local->tm_sec;
    day = local->tm_mday;
    month = local->tm_mon + 1;
    signed char i[50],e[50],c[50],d[50];
    printf("\n\t\t\t\t\tENCRYPTION AND DECRYPTION\n\n");
	

		printf("1.Encrypt the data\n2.Decode the cypher\n\n");
		printf("select your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:
		    {
		    printf("enter the text to encrypt\n");
		    scanf("%s",i);

		    for(a=0;a<strlen(i);a++)
		    {
		        e[a]=encrypt(i[a]);
		    }

		    printf("the encrypted character is  ");
		    for(a=0;a<strlen(i);a++)
		    {
		        printf("%c",e[a]);
		    }printf("\n");
		    }
		


		case 2:
		    {
		    printf("enter the text to decrypt\n");
		    scanf("%s",c);

		   for(a=0;a<strlen(c);a++)
		    {
		        d[a]=decrypt(c[a]);
		    }

		    printf("the decrypted character is:");

		    for(a=0;a<strlen(c);a++)
		    {
		        printf("%c",d[a]);
		    }printf("\n");
		    }break;
		default:printf("\n INVALID CHOICE\n");
		}
		
	
}

int encrypt(int i)
{
    int e;
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
    return e;
}


int decrypt(int c)
{
    int d;

    if(seconds>minutes)
x=((seconds*2)-(minutes*2))+(month-4);
else
x=((minutes*2)-(seconds*2))+(month-4);

y=((hours*seconds)/12)-day;

if(x>y)
t=x-y;
else
t=y-x;

d=c+t;
    return d;

}



