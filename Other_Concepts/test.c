//char<short<int<long


#include<stdio.h>

int main()
{

	unsigned int a,b;
	char c,d;
	float e,f;
	a=-75;
	b=2;
	c='A';
	d='R';
	e=2.0;
	f=65.69;
	char str[] = { "Raj Kumar" };

//	printf("Enter value of c d:");
//	scanf("%c %c",&c,&d);
	
	c=65;
	d='A';
	printf("%s \n",str);
	printf("%d %d %c %d %f %f \n",a,b,c,d,e,f);

	return 0;
}
