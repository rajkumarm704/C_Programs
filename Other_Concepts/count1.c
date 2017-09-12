#include<stdio.h>
int main()
{

unsigned int num,i;
unsigned int temp,count=0;

for(i=0;i<sizeof(num)*8;i++)
{
	num=0xff;
	temp=0x1;
	num=num>>i;
	temp &= num;

	if(temp==1)
		count++;
//	printf("temp:%d\n",temp);
}

printf("%d\n",count);
return 0;
}
