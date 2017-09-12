#include<stdio.h>
int main()
{

	int num1,num2,i;
	printf("Enter total number of pattern character (should be odd): ");
	scanf("%d",&num1);
	printf("\nEnter the number of characters to be entered in the middle of pattern (should be odd): ");
	scanf("%d",&num2);	

	int middle_num1,middle_num2;
	middle_num1=((num1-1)/2)+1;
	middle_num2=((num2-1)/2)+1;
	
	int middle_count=(middle_num1-middle_num2);

	for(i=0;i<=num1;i++)
	{
		if(i<middle_count || i>(middle_count+num2))
		{
			putchar('$');
		}
		else if(i>=middle_count || i<=(middle_count+num2))
		{
			putchar('*');
		}	
	}
	printf("\n");
return 0;
}
