#include<stdio.h>

int find_digits(int num)
{
	int result=0,num_copy;
	num_copy=num/10;

	if(num_copy==0)
		return ++result;

	return ++result+find_digits(num_copy);
}

int main()
{
int num,i,j,result=0,count,mask,temp;

printf("Enter the number:");
scanf("%x",&num);

count=find_digits(num);
//printf("count:%x\n",count);
mask=(1<<4)-1;

for(i=0;i<count;i++)
{
	temp=num&mask;
	result=result<<4;
	result|=temp;
//printf("number:%x\n",result);
	num=num>>4;
}

printf("The number is:%x\n",result);

return 0;
}
