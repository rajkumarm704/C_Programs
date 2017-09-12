#include<stdio.h>

int book_ticket()
{
//	static int i = 0;
	int i = 0;
	i++;
	return i;
}

int main()
{
	int count;
 	count = book_ticket();
	count = book_ticket();
	count = book_ticket();
	count = book_ticket();
	count = book_ticket();
	printf("count is %d\n",count);
	return 0;
}
