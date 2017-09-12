#include<stdio.h>
#include<string.h>

void cne(void);
void ubound(void);
void lbound(void);

void main()
{
	cne();
	ubound();

	int mod_num,num,i,count = 0,j;
	char str[100];

	printf("Enter first string:");
	scanf("%s",str);

	mod_num = strlen(str);

	//Normal string
	for( j = 0; j < mod_num; j++)
	{
		for( i = j; i <= mod_num; i++)
		{
			if(i == mod_num && count != mod_num)
				i = 0;

			else if( count == mod_num)
				break;

			printf("%c",str[i]);

			count++;
		}
		count = 0;
		printf("\n");
	}


	lbound();

}

void cne(void)
{
	system("clear");
	printf("---------------------------------------------------------------------\n");
	printf("Warnings or Errors,if any\n\n");
	system("gcc modulus_func.c -o modulus_func.out");

}

void ubound(void)
{
	printf("---------------------------------------------------------------------\n\n");
}

void lbound(void)
{
	printf("\n\n---------------------------------------------------------------------\n\n");
}


