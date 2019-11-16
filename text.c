//encryption and decryption of a string by inputting date and time
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<string.h>
int hours,minutes,seconds,day,month,x,y,t=0;
int hours1,minutes1,seconds1,day1,month1;

int encrypt(int);
int decrypt(int);

int encrypt(int i)
{
    int e;
    time_t now;
    time(&now);

    struct tm *local = localtime(&now);
    hours = local->tm_hour;
    minutes = local->tm_min;
    seconds = local->tm_sec;

    day = local->tm_mday;
    month = local->tm_mon + 1;



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

    if(seconds1>minutes1)
x=((seconds1*2)-(minutes1*2))+(month1-4);
else
x=((minutes1*2)-(seconds1*2))+(month1-4);

y=((hours1*seconds1)/12)-day1;

if(x>y)
t=x-y;
else
t=y-x;

d=c+t;
    return d;

}

int main()
{
    int a,ch;
    signed char i[50],e[50],c[50],d[50],z='y';
    printf("\n\t\t\tENCRYPTION AND DECRYPTION\n\n");
  
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
            }

            printf("\n hour=%d\nminute=%d\nsecond=%d\ndate=%d\nmonth=%d\n",hours, minutes, seconds, day, month);
            }break;


        case 2:
            {
            printf("enter the text to decrypt\n");
            scanf("%s",c);

            printf("hours=");
            scanf("%d",&hours1);

            printf("minutes=");
            scanf("%d",&minutes1);


            printf("seconds=");
            scanf("%d",&seconds1);


            printf("date=");
            scanf("%d",&day1);

            printf("month=");
            scanf("%d",&month1);


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


