#include<stdio.h>

int even_odd(int num)
{
	num=num%2;
	return num;
}

int main()
{
	int num=200;
	printf("Number is %d\n",num);

	num=even_odd(num);

	if(num==0)
		printf("TRUE\n");
	else
		printf("FALSE\n");
	return 0;
}
