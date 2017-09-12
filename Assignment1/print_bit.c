#include<stdio.h>
int main()
{

	unsigned int num,num_temp,i;
	unsigned int temp;

	while(1)
	{
		printf("Enter the Hexadecimal number: ");
		scanf("%x",&num);
		num_temp=num;

		//Clea the buffer
		while(getchar() != '\n');

		printf("\n");

		printf("Number is %x\n",num);

		//Extract each bit and display it
		for(i=0;i<(sizeof(num)*8);i++)
		{
			num=num_temp;
			temp=0x80000000;
			num=num<<i;
			temp &= num;
	
			if(temp==0)
				printf("0");
			else
				printf("1");
		}

		printf("\n");

		//Ask user for options
		printf("Do you want to continue(Y/N):");
		char ch=getchar();
		while(getchar() != '\n');
		if((ch == 'N' || ch == 'n'))
		{
			break;
		}

	}
	return 0;
}
