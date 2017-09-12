#include<stdio.h>
int main()
{
	int num;
read_again:
	printf("Enter the number between 10 and 50: ");
	scanf("%d",&num);
	if(num>=10 && num<=50)
		printf("You are awesome...\n");
	else
	{
		printf("You don't know counting. Please enter again.\n");
		goto read_again;
	}
return 0;
}
