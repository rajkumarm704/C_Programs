#include<stdio.h>
int main()
{

while(1)
{

	int num1,num2;

	printf("Enter number of terms: ");
	scanf("%d",&num1);

	while(getchar() != '\n');

	int num1_copy=num1,i;
	int middle_num;
	float median=0;
	int even;
	even=num1%2;

	if(even==0)
	{
		middle_num=num1/2;
		for(i=1;i<=num1_copy;i++)
		{
			printf("Enter the numbers: ");
			scanf("%d",&num2);
			while(getchar() != '\n');
			if( i==middle_num || i==(middle_num)+1 )
				median+=num2;
		}
		printf("Median is: %f\n",(float)(median/2));
	}

	else
	{
		middle_num=(num1/2)+1;
		for(i=1;i<=num1_copy;i++)
		{
			printf("Enter the numbers: ");
			scanf("%d",&num2);
			while(getchar() != '\n');
			if(i==middle_num)
				median=num2;
		}
		printf("Median is: %f\n",median);

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
