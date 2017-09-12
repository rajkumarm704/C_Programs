#include<stdio.h>
int main()
{

	int num,mask,mask_inv,temp,n,bit_value,result,i;
	char ch;

while(1)
{
	printf("Enter the number and number of bits: ");
	scanf("%d %d",&num,&n);

	printf("The number is:\n");

	for(i=31;i>=0;i--)
		(1<<i)&num?putchar('1'):putchar('0');

	printf("\n");

	while(getchar() != '\n');

	mask=(1<<n)-1;
	printf("mask: %x\n",mask);

	bit_value=num&mask;
	printf("bit_Value: %x\n",bit_value);

	num=num>>n;
	printf("num: %x\n",num);


	bit_value=bit_value<<(sizeof(num)*8-n);
	printf("bit Value: %x\n",bit_value);

	if(num>0)
	{
		result=num|bit_value;
	}
	else
	{
		mask=(1<<n)-1;
		mask=mask<<(sizeof(num)*8-n);
		mask=~mask;
		num=mask&num;
		result=num|bit_value;
	}

	printf("Result: %d\n",result);
	for(i=31;i>=0;i--)
		(1<<i)&result?putchar('1'):putchar('0');


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
