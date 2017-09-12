#include<stdio.h>
#include<stdlib.h>

typedef enum Bool
{
	bfalse, btrue
}bool_t;

//int bfalse = 26;	//Error

int main()
{
	/* 	Error
	typedef enum Bool
	{
		bfalse, btrue
	}bool_t;
	*/

	system("clear");

	bool_t flag = ( 2 == 3) ;

	int btrue = 0;

	if( flag == btrue )
		printf("Condtion is true.\n");
	else 
		printf("Condtion is false.\n");

	return 0;
}
