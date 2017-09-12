#include<stdio.h>
int main()
{

	int num1=10,num2=20,num3,num4;
	printf("Enter two numbers: ");
	scanf("%d %d %d", &num1,&num2,&num3);

	num4=(num1>num2?(num1>num3?num1:num3):(num2>num3?num2:num3));
//	num3=1?1?(2&3):4?(5%6):7:8;
	printf("The greater number is %d\n",num4);
//	printf("The result is %d\n",num3);
	return 0;
}
