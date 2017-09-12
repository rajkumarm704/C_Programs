#include<stdio.h>

//Reading input from user
int read_int(void)
{
	int i=0;
	char num[20];
	scanf("%s",num);
	
	//Clear buffer
	while(getchar() != '\n');

	//Check if the first character is integer or alphabet;if true return
	if(num[0]<48 || num[0]>57)	
	{
		printf("The entered character is not integer.\n");
		return 0;
	}

	//Check for all characters entered by user and print only integer number
	while(num[i] != '\0')
	{
		//Check if the number is in the range of ASCII value 48 to 57
		if(num[i]>47 && num[i] <58)
			printf("The number is: %c\n",num[i]);
		else
			printf("The entered character is not integer.\n");
		
		//Increment the index
		i++;
	}
	return 0;
}

//Main function
int main()
{
	char ch;
while(1)
{
	//Prompt user for input
	printf("Enter the number:");
	read_int();

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

