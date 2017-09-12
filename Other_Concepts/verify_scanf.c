#include<stdio.h>
int main()
{

int num=100,num2,ret;

while(1)
{

	printf("Enter a number [prsent value is %d]:\n",num);
	ret=scanf("%d %d",&num,&num2);
	while(getchar()!='\n');
	if(ret<2)
		continue;
//		printf("You have entered wrong value. The value of number is %d\n",num);
	else
		break;
//		printf("The value is modified to %d.\n",num);

}
		printf("The value is modified to %d.\n",num);
return 0;
}

