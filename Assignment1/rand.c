#include<stdio.h>
int main()
{

int ch;

srand(6);
while(1)
{
	ch=rand()%6;
	printf("%d\n", ch);
	sleep(1);
}


return 0;
}
