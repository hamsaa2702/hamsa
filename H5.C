#include<stdio.h>
int main()
{
    int rate,simple_interest,principal,time;
    printf("Enter principal, rate and time: ");
    scanf("%d %d %d",&principal,&rate,&time);
    simple_interest=(principal*rate*time)/100;
    printf("Simple Interest is: %d",simple_interest);
    return 0;
} 