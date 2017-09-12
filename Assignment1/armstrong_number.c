#include<stdio.h>

int cube(int num)
{
	return num*num*num;
}

int main()
{

int i,sum=0,result,temp=0,min,max,num,cube_num=0;

printf("Enter the min & max range:");
scanf("%d %d",&min,&max);

for(i=min;i<max;i++)
{
	num=i;
	while(1)
	{
		if(num==0)
			break;

		temp=num%10;
		cube_num=cube(temp);
		sum+=cube_num;
		num=num/10;
	}
	temp=0;
	if(sum==i)
		printf("%d, ",sum);

	sum=0;
}

	putchar('\n');	

return 0;
}	
