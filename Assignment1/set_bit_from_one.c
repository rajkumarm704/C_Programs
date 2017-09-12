#include<stdio.h>
int main()
{
	int num,num_t,i,count=0;
	printf("Enter the number:");
	scanf("%x",&num);
	num_t=0;

	for(i=31;i>=0;i--)
		(1<<i)&num?putchar('1'):putchar('0');

	for(i=31;i>=0;i--)
	{
		if((1<<i)&num)
			break;
		else
			count++;
	}

	putchar('\n');
	count=32-count;

	for(i=0;i<count;i++)
		num_t|=1<<i;

	num_t|=num;

		for(i=31;i>=0;i--)
			(1<<i)&num_t?putchar('1'):putchar('0');

	putchar('\n');

return 0;
}
