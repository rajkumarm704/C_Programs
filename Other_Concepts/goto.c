#include<stdio.h>
int main()
{

	int i=0;
loop:
	if(i<5)
	{
		printf("%d",i);
		i++;
		goto loop;
	}
	return 0;
}
