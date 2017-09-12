#include<stdio.h>

float f2c(float f)
{
	f=(5.0/9.0)*(f-32);
	return f;
}

int main()
{
	float f=200;
	printf("F:%f\n",f);
	f=f2c(f);
	printf("C:%f\n",f);
	return 0;
}
