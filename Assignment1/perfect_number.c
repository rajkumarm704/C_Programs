#include<stdio.h>
int main()
{

//Declarations
	int num,num_copy,i,sum=0,temp;
while(1)
{
	sum=0;

	//Prompt user to enter a number
	printf("Enter a number: ");
	scanf("%d",&num);
	while(getchar() != '\n');

	//Make a copy of original number
	num_copy=num;

		for(i=1;i<num;i++)
		{
			//Store remainder in a variable
			temp=num_copy%i;
	
			//If remainder is zero add and find out sum
			if(temp == 0)
				sum+=i;
	
		}

		//Display result
		if(num==sum)
			printf("Numbe is a perfect number.\n");
		else
			printf("Number is not a perfect number.\n");

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
