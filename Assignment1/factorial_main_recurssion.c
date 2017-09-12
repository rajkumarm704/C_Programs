#include<stdio.h>


int flag=0,num;

int main(int n)
{

	//This code is run only for the first time
	if(flag==0)
	{
		//Prompt user for input
		printf("Enter the number:");
		scanf("%d",&num);
		
		//Clear buffer		
		while(getchar() != '\n');
	}

	//This code is run until factorial is found out
	if(flag==1)
	{
		if(n==0)

			return 1;	//Return 1 when number is 0
		else
			return n*main(n-1);	//Recurssively call main until factorial is found 							//out
	}

	flag=1;
	
	//Display the factorial
	printf("Factorial of %d is: %d\n",num,main(num));
	
	//Reset flag to imitate initial condition
	flag=0;

	//Ask user for options
	printf("\nDo you want to continue(Y/N):");
	char ch=getchar();
	while(getchar() != '\n');
	if((ch == 'Y' || ch == 'y'))
	{
		main(1);
	}

return 0;
}
