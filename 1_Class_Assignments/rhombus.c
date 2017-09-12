#include<stdio.h>
int main()
{

	int num1,num1_copy,i,j;
	char symbol;
	printf("Enter total number of lines and symbol: ");
	scanf("%d %c",&num1,&symbol);	//for 5
	
	num1_copy=num1;		//5
	int total_lines,middle_num;
	total_lines=(num1*2)-1;	//9
	
	middle_num=(((total_lines-1)/2)+1);	//5
	
	for(j=0;j<num1_copy;j++)
	{
		for(i=1;i<=total_lines;i++)
		{
			if(i < middle_num-j || i > middle_num+j )
				putchar(' ');

			else if(i >= middle_num-j || i <= middle_num+j )	
				putchar(symbol);
		}	
			printf("\n");
	}

	for(j=num1_copy-2;j>=0;j--)
	{
		for(i=1;i<=total_lines;i++)
		{
			if(i < middle_num-j || i > middle_num+j )
				putchar(' ');

			else if(i >= middle_num-j || i <= middle_num+j )	
				putchar(symbol);
		}	
			printf("\n");
	}


return 0;
}
