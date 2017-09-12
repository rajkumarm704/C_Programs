#include<stdio.h>
#include<string.h>

int main()
{
	int n, len, t, temp;
	char str[100], delimiter[] = " ";
	char *ptr;
	

	printf("Enter string:");
	scanf("%[a-z A-Z]",str);
	
	while(getchar() != '\n');

	printf("Enter value of n:");
	scanf("%d",&n);

	ptr = strtok(str," ");

	while( ptr != NULL )
	{
		if( strlen(ptr) > n)
		{
			t = ptr[0];

			if( t >= 65 && t <= 90 )
			{
				temp = t - 65;
				ptr[0] = 97 + temp ;
			}
			else if( t >= 97 && t <= 122 )
			{
				temp = t - 97;
				ptr[0] = 65 + temp ;
			}
		}
			printf("%s\n",ptr);

		ptr = strtok(NULL," ");	
	}

	printf("\n");

	return 0;
}
