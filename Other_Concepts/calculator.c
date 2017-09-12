#include<stdio.h>
int main()
{

	int a,b;
	float result;
	char c;
	printf("Enter the expression: ");
	scanf("%d %c %d",&a,&c,&b);
	switch(c)
	{
		case '+' :
				result=a+b;
				printf("Result of expression is %f.\n",result);break;
		case '-':
				result=a-b;
				printf("Result of expression is %f.\n",result);break;
		case '*':
				result=a*b;
				printf("Result of expression is %f.\n",result);break;

		case '/':
				result=a/b;
				printf("Result of expression is %f.\n",result);break;

		default:printf("You have entered Special Charater.\n");break;
	}
	return 0;
}
