#include<stdio.h>
#include<stdlib.h>

typedef enum Bool
{
	bfalse, btrue
}bool_t;


bool_t getTrue()
{
	return btrue;
}

int main()
{

	
	system("clear");

	bool_t flag = ( 2 == 3) ;

	bool_t c1;

	printf("Size of bool_t:%d\n",sizeof(bool_t) );
	printf("Size of c1:%d\n",sizeof(c1) );

	if( flag == btrue )
		printf("Condtion is true.\n");
	else 
		printf("Condtion is false.\n");

	return 0;
}
