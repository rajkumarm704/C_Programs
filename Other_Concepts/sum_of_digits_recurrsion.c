#include<stdio.h>
int sum_digits(int num)
{
	int num_copy,temp;
	if(num == 0)
		return 0;
	num_copy=num;	
	temp=num_copy%10;
	num_copy=num_copy/10;
//	printf("Number before reccursive call: %d,temp:%d\n",num_copy,temp);
	return temp+sum_digits(num_copy);
	
}

int main()
{
	int num;
	printf("Enter the number:");
	scanf("%d",&num);
	printf("Thr result is:%d\n",sum_digits(num));
	return 0;
}
