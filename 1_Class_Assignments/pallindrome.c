#include<stdio.h>
int main()
{
	int num,rev_num=0,num_orig,num_copy,temp,lb,i=0;
	printf("Enter the number: ");
	scanf("%d",&num);
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

return 0;
}
