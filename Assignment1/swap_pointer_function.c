#include<stdio.h>

//Swap Function
void swap(int *x,int *y)
{
	int temp;
	
//Store first number in a temporary variable	
	temp=*x;
//Copy second number to first number
	*x=*y;
//Copy first number from temporary variable to second nuumber
	*y=temp;
}

int main()
{
	int x,y;

while(1)
{
	printf("Enter two numbers:");
	scanf("%d %d",&x,&y);
//Display original numbers
	printf("x :%d\ty:%d\n",x,y);
//Function call
	swap(&x,&y);
//Display swapped numbers
	printf("x :%d\ty:%d\n",x,y);

	//Ask user for options
	printf("Do you want to continue(Y/N):");
	char ch=getchar();
	while(getchar() != '\n');
	if((ch == 'N' || ch == 'n'))
	{
		break;
	}


}
	return 0;
}
