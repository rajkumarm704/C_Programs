#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void main()
{

	system("gcc puzzle.c -o puzzle.out");

	printf("Compiled\n");

	char buffer[100] =  "[_o_e_m_on]",temp[100];
	char missing[100] = "[H_n_y_o__]";
	int ch,i,count = 0;


	while(1)
	{		
		system("clear");
	printf("Done\n");

	printf("\n	# Your question of the day #\n	A part of it you find in sky\n	It has something which is sweet\n	You would like to go after marriage.\n\n");

	printf("The word is ");
	printf("%s",buffer);
	printf(":");





		ch = getchar();
		fflush(stdout);

		for( i = 0; i < strlen(missing); i++)
		{
			if( ch == missing[i])
			{
				buffer[i] = missing[i];
				count++;
				break;
			}
		}
/*		printf("The word is ");
		printf("%s",buffer);
		printf(":");
		
*/		if(count == 4)
		{
				
		system("clear");

			printf("\n	# Your question of the day #\n	A part of it you find in sky\n	It has something which is sweet\n	You would like to go after marriage.\n\n");

			printf("The word is ");
			printf("%s",buffer);
			printf(":");
			printf("You got it...");
			break;
		}
	}

printf("\n");
}

	
