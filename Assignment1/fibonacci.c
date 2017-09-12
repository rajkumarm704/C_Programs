#include<stdio.h>
int main()
{

//Declarations

char ch;



while(1)
{
	int num,sum=0,temp=0,fnum=1;
	//Prompt user for input
	printf("Enter the number: ");
	scanf("%d",&num);

	//Clear the \n character
	while(getchar() != '\n');

	while(1)
	{
		//Generate fibonacci number
		temp=sum;
		sum = sum + fnum;
		fnum=temp;

		if(fnum>=num)
			break;
		
		//Display fibonacci number
		printf("fnum:%d, \n",fnum);
		printf("num:%d, \n",num);
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
