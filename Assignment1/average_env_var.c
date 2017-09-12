#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[], char *envp[])
{
	system("clear");
	int i, j, len = 0;
	char *ptr;
	float sum = 0;

	for( i = 0; envp[i] != NULL; i++ )
	{
		if(strstr(envp[i],"AVG") != NULL )
		{
			printf("envp[%d]:%s\n",i,envp[i]);
			break;
		}
	}
	
	ptr = strchr(envp[i],'=');
	ptr++;
	
	len = strlen(ptr);

	for ( i = 0; i < len; i++ )
	{
		sum += ptr[i] - 48;
	}

	printf("average:%f\n",(float)sum/len);

	

	return 0;
}
