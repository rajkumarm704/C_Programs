/** USEFUL MACROS **/

#include<stdio.h>
#include<stdlib.h>

int main()
{
	system("clear");

	printf("Program:\"%s\" ", __FILE__);
	printf("was compiled on %s at %s. " , __DATE__ , __TIME__);
	printf("This print is from function:\"%s\" ", __func__);
	printf("at line %d\n", __LINE__);

	return 0;
}
