#include<stdio.h>
int main()
{
	int a,b,i;
	printf("Enter two numbers: ");
	scanf("%d %d",&a,&b);
	int result=0;
	for(i=0;i<b;i++)
	{
		result=result+a;
	}
	printf("Result is %d.\n",result);
return 0;	

}


