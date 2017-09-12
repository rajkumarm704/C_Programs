#include<stdio.h>

int sum(int n)
{

	if(n==0)
		return 0;
	else
		return n+sum(n-1);
}

int num=0;

int main()
{

printf("Enter the number:");
scanf("%d",&num);
printf("Sum of %d natural number is : %d\n",num,sum(num));

return 0;
}
