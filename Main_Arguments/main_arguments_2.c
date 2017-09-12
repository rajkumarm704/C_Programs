#include<stdio.h>				//Date:23rd June, 2017
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[], char *envp[])
{
	system("clear");
	int idx, len, count = 0, i, j, k, l, sum =  0;
	char *ptr, *ptr1;

//	len = strlen(argv[1]);



	
	for ( idx = 0; envp[idx] != NULL; idx++ )
	{
		if(  strstr( envp[idx], argv[1]) )
		{
			ptr = strchr( envp[idx], '=' );			
//			printf("envp[%d]: %s\n",idx, envp[idx] );	
			break;
		}
	}
	printf("Environment variable: %s\n",envp[idx]);
	ptr++;

	printf("string: %s\n",ptr );	

	ptr1 = strtok(ptr,argv[2]);

	while( ptr1 != NULL )
	{
		sum += atoi(ptr1);
		printf("%s\n",ptr1);
		ptr1 = strtok(NULL, argv[2]);
	}

	printf("sum: %d\n",sum );	

	return 0;
}
