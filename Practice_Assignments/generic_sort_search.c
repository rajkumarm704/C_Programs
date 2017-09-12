#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>

void read_data(void **vptr, int n, int data_type)
{
	int i;

	switch(data_type)
	{
		case 1:
			*vptr = malloc(n * sizeof(int) );
			for( i = 0; i < n; i++ )
				scanf("%d", ( (int *)*vptr + i) );
			break;
		case 2:
			*vptr = malloc(n * sizeof(char) );
			__fpurge(stdin);
			for( i = 0; i < n; i++ )
			{
				scanf("%c", ( (char *)*vptr + i) );
				__fpurge(stdin);
			}
			break;
		case 3:
			*vptr = malloc(n * sizeof(float) );
			for( i = 0; i < n; i++ )
				scanf("%f", ( (float *)*vptr + i) );
			break;
	}
//	return vptr;
}

void print_data(void **vptr, int n, int data_type)
{
	int i;
	switch(data_type)
	{
		case 1:
			for(i = 0; i < n; i++ )
				printf("%d ", *( (int *)*vptr + i) );
			break;
		case 2:
			for(i = 0; i < n; i++ )
				printf("%c ", *( (char *)*vptr + i) );
			break;
		case 3:
			for(i = 0; i < n; i++ )
				printf("%.2f ", *( (float *)*vptr + i) );
			break;
	}
	printf("\n");
}

void sort_data(void **vptr, int n, int data_type)
{
	int i, j;
	void *temp;

	switch(data_type)
	{
		case 1:
			temp = malloc( sizeof(int) );
			for(i = 0; i < n; i++ )
			{
				for(j = 1; j < n; j++ )
				{
					if( *( (int *) *vptr + j - 1 ) > *( (int *) *vptr + j ) )
					{
						*( (int *)temp ) = *( (int *)*vptr + j - 1 );
						*( (int *)*vptr + j - 1 ) = *( (int *)*vptr + j );
						*( (int *)*vptr + j ) = *( (int *)temp );
					}
				}
			}
			break;
		case 2:
			temp = malloc( sizeof(char) );
			for(i = 0; i < n; i++ )
			{
				for(j = 1; j < n; j++ )
				{
					if( *( (char *) *vptr + j - 1 ) > *( (char *)*vptr + j ) )
					{
						*( (char *)temp ) = *( (char *)*vptr + j - 1 );
					*( (char *)*vptr + j - 1 ) = *( (char *)*vptr + j );
						*( (char *)*vptr + j ) = *( (char *)temp );
					}
				}
			}
			break;
		case 3:
			temp = malloc( sizeof(float) );
			for(i = 0; i < n; i++ )
			{
				for(j = 1; j < n; j++ )
				{
					if( *( (float *)*vptr + j - 1 ) > *( (float *)*vptr + j ) )
					{
					*( (float *)temp ) = *( (float *)*vptr + j - 1 );
					*( (float *)*vptr + j - 1 ) = *( (float *)*vptr + j );
					*( (float *)*vptr + j ) = *( (float *)temp );
					}
				}
			}
			break;
	}
	
	free(temp);

//	return vptr;
}

int main()
{

	system("clear");

	int option, n;
	void *vptr;
	printf("Choose a Data Type:\n1. Integer\n2. Character\n3. Float\nYour option: ");
	scanf("%d",  &option);

	printf("Enter the number of elements:"),scanf("%d", &n);
	
	printf("Enter the elements:");

	read_data(&vptr, n, option);
//	vptr = read_data(vptr, n, option);

	print_data(&vptr, n, option);

	sort_data(&vptr, n, option);
//	vptr = sort_data(vptr, n, option);

	print_data(&vptr, n, option);
			
	return 0;
}
