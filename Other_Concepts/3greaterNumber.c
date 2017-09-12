#include<stdio.h>
int main()
{
	int a,b,c;
	printf("Enter three numbers: ");
	scanf("%d %d %d",&a,&b,&c);
	if(a>b && a>c)
		printf("\n%d is greatest.\n",a);
	else if(b>a && b>c)
		printf("\n%dis greatest.\n",b);
	else if(c>a&&c>b)
		printf("\n%d is greatest.\n",c);
return 0;
}
