#include<stdio.h>
int main()
{
	int a,b;
	printf("Enter two number: ");
	scanf("%d %d",&a,&b);
	if(a>b)
		printf("\n%d is greater than %d\n",a,b);
	else if(a==b)
		printf("\nBoth numbers are equal.\n");
	else
		printf("\n%d is greater than %d\n",b,a);
return 0;
}
