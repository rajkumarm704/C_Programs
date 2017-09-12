#include<stdio.h>
int main()
{

unsigned int num,i;
unsigned int temp;
num=0x49;
printf("\n");
printf("Number is %x\n",num);
for(i=0;i<(sizeof(num)*8);i++)
{
	num=0x49;
	temp=0x80000000;
	num=num<<i;
	temp &= num;
	
	if(temp==0)
		printf("0");
	else
		printf("1");
}

printf("\n");
return 0;
}
