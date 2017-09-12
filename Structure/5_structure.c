/**	Pointer to structure 	**/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio_ext.h>

struct Student
{
	int id;
	char name[20];
	char address[60];
};

int main()
{

	system("clear");

	int i;

	struct Student sarr[2] = { { 750, "Yoo mann!!!", "India.`.`.`.`." }, 
				   { 546, "Yoo Broo...", "India=====>"} };

	for( i = 0; i < 2; i++)
	{
		printf("Value of sarr[%d].id\t\t: %d \n", i, sarr[i].id);
		printf("Value of sarr[%d].name\t\t: %s \n", i, sarr[i].name);
		printf("Value of sarr[%d].address\t: %s \n\n", i, sarr[i].address);
	}
	
	return 0;
}
