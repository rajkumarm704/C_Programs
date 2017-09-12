#include<stdio.h>
#include<stdlib.h>

enum Color
{
//	white = 'A', red = 99, blue = red + 10
	white = 'A', red , blue
};

int main()
{

	system("clear");

	printf("White:%d\n",white);
	printf("Red:%d\n",red);
	printf("Blue:%d\n",blue);

	return 0;
}
