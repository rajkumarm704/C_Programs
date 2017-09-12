#include<stdio.h>
int main()
{

printf("Enter the number:");
scanf("%d",&num);

if(num%2==0)
	num|=1;

printf("The incremented number is:%d",num);
	

return 0;
}
