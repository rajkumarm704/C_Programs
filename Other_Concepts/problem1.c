#include<stdio.h>
#include<unistd.h>

int counter(void)
{
	static int count;
	count++;
	return count;
}

int main()
{
	int count=0;
while(1)
{
	count=counter();
	printf("The count is %d, ",count);
	getchar();

/*	if(count%5==0)
	{
		printf("\n");
	}
	sleep(1);
*/}
return 0;
}
