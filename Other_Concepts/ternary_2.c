#include<stdio.h>
int main()
{

	int num,i;

while(1)
{
	printf("Enter the number to get its bit pattern: ");
	scanf("%d",&num);
	while(getchar() != '\n');
//	num=5;
	
	for(i=31;i>=0;i--)
		(1<<i)&num?putchar('1'):putchar('0');


	//Ask user for options
	printf("\nDo you want to continue(Y/N):");
	char ch=getchar();
	while(getchar() != '\n');
	if((ch == 'N' || ch == 'n'))
	{
		break;
	}


}
	return 0;
}
