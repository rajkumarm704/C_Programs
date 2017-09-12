#include<stdio.h>
int my_pow(int num,int pow)
{
	if(pow==1)
		return num;
	else
		return num*my_pow(num,pow-1);
}

int main()
{

	int num,pow;
	printf("Enter the number and its power:");
	scanf("%d %d",&num,&pow);
		if(pow == 0 )
		{
			printf("The result is 1.\n");
			goto end;
		}
	printf("The result is: %d.\n",my_pow(num,pow));

	
	end:
	xmain();
	return 0;
}
