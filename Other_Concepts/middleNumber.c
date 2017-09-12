#include<stdio.h>
int main()
{
	int a,b,c;
	printf("Enter three numbers: ");
	scanf("%d %d %d",&a,&b,&c);
	printf("The middle number is ");

	if(a>b&&a<c||a<b&&a>c)
		printf("%d.\n",a);
	else if(b>a&&b<c||b<a&&b>c)
		printf("%d.\n",b);
	else if(c>b&&c<a||c<b&&c>a)
		printf("%d.\n",c);
return 0;
}
