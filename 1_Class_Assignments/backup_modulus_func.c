#include<stdio.h>
void main()
{

	int mod_num,num,i,count = 0;

	printf("Enter modulus number:");
	scanf("%d",&mod_num);

	printf("Enter number:");
	scanf("%d",&num);

	for( i = num; i <= mod_num; i++)
	{
		if(i == mod_num && count != mod_num)
			i = 0;

		else if( count == mod_num)
			break;

		printf("%d, ",i);

		count++;
	}

		printf("\n");
}
