// va_list is equivalent to a pointer to memory location (similar to malloc memory pointer) and we just need to read elements depending upon their datatype (as we do in void pointer).

/**********************  PICTORIAL REPRESENTATION (ANALOGY) ******************************

			    int     int    float   int     float
	 ________	   _____   _____   _____   _____   _____
  	|  1000  | -----> |  E1	| |  E2	| |  E3	| |  E4	| |  E5	| 
	 ````````	   `````   `````   `````   `````   `````
	 va_list	   (1000)  (1004)  (1008)  (1012)  (1016)		
	 (5000)


*****************************************************************************************/


#include<stdio.h>				//Date:29th June, 2017
#include<stdlib.h>
#include<stdarg.h>
#include<string.h>

float average(const char *str, ... )
{
	va_list ap;
	int i, len, count = 0;
	float sum = 0;
	len = strlen(str);

	va_start(ap, str);
	
	for(i = 1; str[i] != '\0' ; i++ )
	{
		if(str[i - 1] == '%' && str[i] == 'd' )
		{
			sum += va_arg(ap, int);
			count++;
		}
		else if(str[i - 1] == '%' && str[i] == 'f' )
		{
			sum += va_arg(ap, double);
			count++;
		}
	}

	va_end(ap);

	return (float)sum/count;
}


int main()
{
	system("clear");

	float avg;

	avg = average("dfdfdfdf%d %d %f %d %f", 10, 22,  3.5, 21, 7.2  );
//	avg = average("%d %d %f %d %f", 1, 2,  3.0, 4, 5.0  );

	printf("Average is %.2f\n",avg );

	return 0;
}
