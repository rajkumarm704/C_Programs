#include<stdio.h>
int main()
{
	//Declarations
	int hnum,temp;

	while(1)
	{
		printf("Enter the Hexadecimal number: ");
		scanf("%x",&hnum);

		//Clear Buffer
		while(getchar() != '\n');
	
		//Find the leat significant bit
		temp=hnum&1;

		//If LSB is 0, it is even else it's odd
		if(temp==0)
			printf("Number is Even.\n");
		else
			printf("Number is Odd.\n");

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

