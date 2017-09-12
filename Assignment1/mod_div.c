#include<stdio.h>
int main()
{

	int num1,num2,rdiv,rmod;
	printf("Enter two numbers: ");
	scanf("%d %d",&num1, &num2);

	rdiv=(num1/num2);
	rmod=(num1%num2);	

	printf("The division is: %d and the modulus is: %d\n",rdiv,rmod);
	return 0;
}
