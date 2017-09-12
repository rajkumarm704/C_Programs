#include<stdio.h>
#include<stdlib.h>

typedef enum _Color 
{
	white = 'A', red , blue
}Color_t;

int main()
{

	system("clear");
	Color_t col;
	col = 65;

	if( col == white )
		printf("Color is white\n");

	else
	printf("Color is not white\n");

	return 0;
}
