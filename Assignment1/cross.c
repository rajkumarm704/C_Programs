#include<stdio.h>
int main()
{

while(1)
{

	//Declarations
	int num1,num1_copy,i,j,pos1,pos2,even,s_index=0,length=0,length_copy;
	char symbol[20];

	//Prompt user for Input
	printf("Enter total number of lines: ");
	scanf("%d",&num1);	
	
	printf("Enter the name: ");
	scanf("%s",symbol);

	//Clear any characters from buffer
	while(getchar() != '\n');

	//Calculate the length of name entered
	while( symbol[s_index] != '\0')
	{
		s_index++;
		length++;
	}	
	
	//Make a copy of length of name
	length_copy=length;
	num1_copy=num1;	

	//Declaratioins
	int offset,total_lines,middle_num;

	//Find if the number of lines are even or odd
	even=num1%2;	

	//Set values of variables depending upon even or odd numbers
	if(even == 0)
	{
		total_lines=num1;
		middle_num=num1/2;
	}
	else
	{
		total_lines=num1;	
		middle_num=(num1+1)/2;
	}

	offset=num1-1;	

	for(j=1;j<=total_lines;j++)
	{
		//Find out positions for Odd number of lines
		if(j<middle_num && even != 0)
		{
			pos1=j;			//1,2.3,4
			pos2=j+offset;		//7,6,5,4
			offset-=2;
		}
		else if(j==middle_num && even != 0)
		{
			pos1=pos2=j;
			offset=2;
		}
		else if(j>middle_num && even != 0)
		{
			pos1=j-offset;		//7,6,5,4
			pos2=j;			//1,2.3,4
			offset+=2;
		}

		//Find out positions for even number of lines
		else if(j<middle_num && even == 0)
		{
			pos1=j;			//1,2.3,4
			pos2=j+offset;		//7,6,5,4
			offset-=2;
		}
		else if(j==middle_num && even == 0)
		{
			pos1=j;
			pos2=j+1;
			offset=1;
		}
		else if(j==middle_num+1 && even == 0)
		{
			pos1=j-1;
			pos2=j;
			offset=1;
		}
		else if(j>middle_num+1 && even == 0)
		{
			offset+=2;
			pos1=j-offset;		//7,6,5,4
			pos2=j;			//1,2.3,4

		}

		//Print the pattern
		for(i=1;i<=total_lines;i++)
		{
			length=length_copy;
			if(i<=middle_num)
			{
				if(i != pos1 )
				{
					//Print empty characters
					while(length>0)
					{
						putchar(' ');
						length--;
					}
				}

				else if(i == pos1)
					printf("%s",symbol);
			}
			
			else if(i>middle_num)
			{
				if(i != pos2 )	
				{
					//Print empty characters
					while(length>0)
					{
						putchar(' ');
						length--;
					}
				}
				else if(i == pos2)
					printf("%s",symbol);
			}		
		}
		printf("\n");
	}

		//Ask user for options
		printf("Do you want to continue(Y/N):");
		char ch=getchar();
		while(getchar() != '\n');
		if(!(ch == 'Y' || ch == 'y'))
		{
			break;
		}

}
return 0;
}




