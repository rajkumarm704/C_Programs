#include<stdio.h>
#include<string.h>

int main()
{
	int len, count = 0, i = 0, j;
	char str[100];
	char *ptr;
	char *sptr[20];
	

	printf("Enter string:");
	scanf("%[a-z A-Z]",str);
	
	while(getchar() != '\n');

	ptr = strtok(str," ");

	int arr[100];

	while( ptr != NULL )
	{
		sptr[i] = ptr;
		len = strlen(ptr);
		arr[i] = len;
		i++;

		count++;
//		printf("%s\n",ptr);
		ptr = strtok(NULL," ");	
	}

/*	printf("unsorted array is.\n");
	for( i = 0; i < count; i++ )
		printf("%d ",arr[i]);

	printf("\n");

	for( i = 0; i < count; i++ )
		printf("%s\n",sptr[i]);
*/
	char *tptr;
	int tdata = 0;

	for ( i = 0; i < count; i++ )
	{
		for ( j = 1; j < count; j++ )
		{
			if( arr[ j - 1 ] > arr[ j ] )
			{
				tdata = arr[ j - 1 ];
				arr[ j - 1 ] = arr[ j ];
				arr[ j ] = tdata;

				tptr = sptr [ j - 1 ];
				sptr [ j - 1 ] = sptr [ j ];
				sptr [ j ] = tptr;
			}
		}
	}

/*
	printf("Sorted array is.\n");
	for( i = 0; i < count; i++ )
		printf("%d ",arr[i]);

	printf("\n");

	for( i = 0; i < count; i++ )
		printf("%s\n",sptr[i]);
*/
	printf("\n");

	printf("Smallest word in the string is ' %s ' and the largest word int he string is ' %s '.\n",sptr[0], sptr[count - 1]);


	printf("\n");

	return 0;
}
