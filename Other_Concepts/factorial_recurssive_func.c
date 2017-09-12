#include<stdio.h>

int fact(int n)
{

	if(n==0)
		return 1;
	else
		return n*fact(n-1);
}

int num=0;

int main()
{

/*printf("Enter the number:");
scanf("%d",&num);
printf("Factorial of %d is: %d\n",num,fact(num));
*/
printf("Main called %d  times.\n",num);
num++;
main();
return 0;
}
