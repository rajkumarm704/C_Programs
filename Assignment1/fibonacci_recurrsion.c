#include<stdio.h>

//Fibonacci Function
int fibonacci(int num,int sum,int temp,int fnum)
{
//	num,sum=0,temp=0,fnum=1;

	//Generate fibonacci number
	temp=sum;
	sum = sum + fnum;
	fnum=temp;

	if(fnum<=num)
	{
		//Display fibonacci number
		printf("%d, ",fnum);	
		return fibonacci(num,sum,temp,fnum);
	}
	else
		return 1;
}

//Main Function
int main()
{

	//Declarations

	char ch;
	int num,sum=0,temp=0,fnum=1;

	//Prompt user for input
	printf("Enter the number: ");
	scanf("%d",&num);

	//Clear the \n character
	while(getchar() != '\n');

	fnum=fibonacci(num,0,0,1);

	if(fnum==1)
		printf("\nSuccess.\n");
	else
		printf("\nFailure.\n");


	//Ask user for options
	printf("\nDo you want to continue(Y/N):");
	ch=getchar();
	while(getchar() != '\n');
	if((ch == 'Y' || ch == 'y'))
	{
		main();
	}

return 0;
}
