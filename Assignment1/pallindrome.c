#include<stdio.h>
int main()
{
	int num,rev_num,num_orig,num_copy,temp,lb,i;
	char ch;
while(1)
{
	rev_num=0,i=0;
	printf("Enter the number: ");
	scanf("%d",&num);

	while(getchar() != '\n');

	num_orig=num;
	num_copy=num;	
	while(1)
	{

		temp=num%10;
		num=num/10;
		rev_num=rev_num*10+temp;

		num_copy=num_copy/10;
		lb=num_copy/10;

		if(lb == 0)
		{
			temp=num%10;
			num=num/10;
			rev_num=rev_num*10+temp;
			break;
		}
	}
	printf("rev_num:%d\n",rev_num);

	if(num_orig==rev_num)
		printf("Number is pallindrome.\n");
	else
		printf("Number is not pallindrome.\n");

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
