#include<stdio.h>
//#include"a.c"
//#include"c.c"

extern void print(void);
extern void print1(void);

extern int x;
//int y;
//int x;
int main()
{
//	y = 20;
//	x = 101;

//	print();
	printf("x:%d\n",x);

//	print1();
	printf("x:%d\n",x);

//	printf("y:%d\n",y);
	printf("x:%d\n",x);

	return 0;
}
