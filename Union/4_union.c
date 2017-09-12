#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

union Data
{
	float f;
	struct
	{
		unsigned mantissa : 23;
		unsigned exponent : 8 ;
		unsigned sign : 1;
	};
}d1;


/* 1
union Data
{
	float f;
	struct
	{
		unsigned mantissa : 23;
		unsigned exponent : 8 ;
		unsigned sign : 1;
	}fb;

}d1;
*/


/* 1
struct Fbits
{
	unsigned mantissa : 23;
	unsigned exponent : 8 ;
	unsigned sign : 1;
};

union Data
{
	float f;
	struct Fbits fb;
}d1;
*/

int main()
{

	system("clear");

	int i;
	void *vptr = malloc( sizeof(float) );
	float f;

while(1)
{
	printf("Enter a float number:"), scanf("%f", &f);

	*( (float *)vptr ) = f;
	d1.f = f;

	printf("Sign:%x\n",d1.sign);
	printf("Exponent:%x\n",d1.exponent);
	printf("Mantissa:%x\n",d1.mantissa);

	printf("\nFloat value: ");
	for( i = 3; i >= 0; i-- )
		printf( "%hhx ", *( (char *)vptr + i ) );

	printf("\n\n");
}
	return 0;
}
