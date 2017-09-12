#include<stdio.h>
int x=0;

int call_func(){return x;}

int main()
{
	int x=11;

	{
		int x=22;
		{
			int x=33;
			printf("Block 3:%d\n",x);
		}
		printf("Block 2:%d\n",x);
	}
	printf("Block 1:%d\n",x);

	x=call_func();
	printf("After Call:%d\n",x);
	return 0;
}
