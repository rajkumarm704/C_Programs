#include<stdio.h>
void square_cube(int *p,int *q)
{
	*p=*p**p;
	*q=*q**q**q;
}

int main()
{
	int x=5,y=5;
	int *p,*q;
//	p=&x;
//	q=&y;	
	printf("Before call:%d\n",x);
//	square_cube(p,q);
	square_cube(&x,&y);
	printf("After call:%d\n",x);
	printf("After call:%d\n",y);

	return 0;
}
