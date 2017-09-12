`#include<stdio.h>
void swap(int *x,int *y)
{
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}

int main()
{
	int x=5,y=20;
	printf("x :%d\ty:%d\n",x,y);
	swap(&x,&y);
	printf("x :%d\ty:%d\n",x,y);

	return 0;
}
