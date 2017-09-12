#include<stdio.h>
int main()
{

	unsigned int num,num_copy,i;//,hnum;
	unsigned int temp,temp_copy,count=0,lnib,hnib;

	unsigned char hnum;
	printf("Enter Hex Number: ");
	scanf("%hhx",&hnum);
	num=hnum;
	num_copy=num;
	printf("Number:%x\n",num);
	temp=0x0f;
	temp &= num;
	temp_copy=temp;
	temp=0xf0;
	temp &= num_copy;
	temp_copy=temp_copy<<4;
	temp=temp>>4;
	temp |= temp_copy;
	printf("Swapped Number:%x\n",temp);

	return 0;

}
