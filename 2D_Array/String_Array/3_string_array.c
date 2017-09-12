#include<stdio.h>
#include<stdlib.h>

void print_array( char *arr[] )
{
	int i = 0;

	printf("\nIn function\n");

	while( arr[i] != NULL )
	{
		printf("%d. %s\n",i + 1, arr[i]);
		i++;
	}
}

int main()
{
	system("clear");

	int i,j;
	char *sarr[] = { "File", "Edit", "View", "Help", NULL };
	int choice;

	print_array( sarr );

	printf("Enter you choice:");
	scanf("%d",&choice);

	printf("Your choice is %s\n", sarr[choice - 1] );

	return 0;

}
