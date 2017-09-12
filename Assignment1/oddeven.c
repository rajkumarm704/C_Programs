#include<stdio.h>
int main()
{

//Declarations
int num,even,odd;
char ch;


while(1)
{

	//Prompt user to enter number
	printf("Enter the number: ");
	scanf("%d",&num);

	//Clear the \n character
	while(getchar() != '\n');


	//Find if the number is even or odd
	even=num%2;

	//Display appropriate message
	if(num>=0)
	{
		printf("Number is positive.\n");
	
		if(even == 0)
			printf("Number is even.\n");
		else if(even!=0)
			printf("Number is odd.\n");
	}

	else if(num<0)
	{
		printf("Number is negative.\n");
	
		if(even == 0)
			printf("Number is even.\n");
		else if(even!=0)
			printf("Number is odd.\n");
	}	



		//Ask user for options
		printf("Do you want to continue(Y/N):");
		ch=getchar();
		while(getchar() != '\n');
		if(!(ch == 'Y' || ch == 'y'))
		{
			break;
		}


}
return 0;
}
