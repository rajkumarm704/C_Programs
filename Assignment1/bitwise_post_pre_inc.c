#include<stdio.h>
void pre_inc(int *num)
{
	int num_copy;
	num_copy=*num;
	
	if( *num % 2 == 0 )
	{
		*num |= 1;
	}
	else if( *num % 2 != 0 )
	{
		
	}
}

int post_inc(int *num)
{
	int temp;
	temp=*num;
	pre_inc(num);
	return temp;
}

int main()
{
	char ch;
	int num,option,temp;
	int *nptr;
	nptr=&num;

while(1)
{

	printf("Enter the number:");
	scanf("%x",&num);
	
	printf("Enter the operation:\n");
	printf("1:Pre Increment.\n");
	printf("2.Post Increment.\n");
	scanf("%d",&option);
	while(getchar() != '\n');
	printf("The number is %x\n",num);

	if(option == 1)
	{
		pre_inc(nptr);
		printf("The number after func %x\n",*nptr);
		printf("The number in memory %x\n",*nptr);
	}
	else if(option == 2)
	{
		temp=post_inc(nptr);
		printf("The number after func %x\n",temp);
		printf("The number in memory %x\n",*nptr);
	}

	//Ask user for options
	printf("\nDo you want to continue(Y/N):");
	ch=getchar();
	while(getchar() != '\n');
	if(!(ch == 'Y' || ch == 'y'))
	{
		break;
	}
}
	return 0;
}
