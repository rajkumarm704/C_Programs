#include<stdio.h>
int main()
{

int num1=1,num2=0;
if(++num1||num2++)
	printf("num1:%d num2:%d\n",num1,num2);

num1=1,num2=0;
if(++num1&&++num2)
	printf("1st Statement num1:%d num2:%d\n",num1,num2);
else
	printf("2nd Statement num1:%d num2:%d\n",num1,num2);


return 0;
}
