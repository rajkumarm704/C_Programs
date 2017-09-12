#include<stdio.h>
int main()
{

	int num,num_temp,nnum,temp,i;
	unsigned int a,b;
	char ch;
	
while(1)
{
	printf("Enter the number: ");
	scanf("%x",&num);
	printf("Number is:%hhx\n",num);

	while(getchar() != '\n');

	a=(unsigned int)num;
	printf("Type casted:%hhx\n",a);


	num=~a+1;
	num=~num+1;
	num_temp=num;
	

	printf("Number in Signed int:%hhx\n",num);
	printf("Number in unsigned int:%hhx\n",a);

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
	for(i=0;i<(sizeof(num)*8);i++)
		{
			num=a;
			temp=0x80000000;
			num=num<<i;
			temp &= num;
	
			if(temp==0)
				printf("0");
			else
				printf("1");
		}



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


/*

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

*/
