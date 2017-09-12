#include<stdio.h>				//Date:29th June, 2017
#include<stdlib.h>

float add(int x, int y)
{
	return x + y;
}

float sub(int x, int y)
{
	return x - y;
}

float mul(int x, int y)
{
	return x * y;
}

float division(int x, int y)
{
	return (float)y / x;
}

float (*get_func(int option))(int x, int y)
{
	switch(option)
	{
		case 1: return add;
		case 2: return sub;
		case 3: return mul;
		case 4: return division;
		default: printf("Invalid Option.\n");return NULL;
	}
}

int main()
{
	system("clear");

	int option, num1, num2;
	float (*f)(int, int);
	
start:	printf("Select an operation to perform:\n1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\nYour option:");
	scanf("%d", &option );

	f = get_func(option);

	printf("Enter two numbers:");
	scanf("%d %d", &num1, &num2 );

	printf("Result: %.2f\n\n", f(num1, num2));

	goto start;

	return 0;
}
