#include<stdio.h>

extern int func_1(void);
extern int func_2(void);

int main()
{
	func_1();
	func_2();

	return 0;
}
