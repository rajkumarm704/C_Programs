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

int main()
{
	system("clear");

	int option, num1, num2;
	float (*a[4])(int, int) = { add, sub, mul, division };

start:	printf("Select an operation to perform:\n1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\nYour option:");
	scanf("%d", &option );

	if(  option > 4 || option < 1 )
	{
		while(getchar() != '\n');
		printf("Invalid option. Please try again.\n");
		goto start;
	}


	printf("Enter two numbers:");
	scanf("%d %d", &num1, &num2 );

	printf("Result: %.2f\n\n", a[option - 1](num1, num2));

	goto start;

	return 0;
}
