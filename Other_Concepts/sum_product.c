#include<stdio.h>
void sum_product(int *a,int *b,int *sum_a,int *prod_a)
{
	int sum,product;
	sum=*a+*b;
	product=*a**b;
	*sum_a=sum;
	*prod_a=product;
}

void sum_product_2(int *a,int *b)
{
	int sum,product;
	sum=*a+*b;
	product=*a**b;
	*a=sum;
	*b=product;
}

int main()
{
	int x=5,y=20;
	int sp,pp;
	printf("x :%d\ty:%d\n",x,y);
//	sum_product(&x,&y,&sp,&pp);
	sum_product_2(&x,&y);
	printf("Sum :%d\tProduct:%d\n",x,y);
	return 0;
}
