#include<stdio.h>
int x=0;

float f2c(float f)
{
	f=(5/9)*(f-32);
	return f;
}

int main()
{
	float f=132;
	printf("F:%f\n",f);
	f=f2c(f);
	printf("C:%f\n",f);
	return 0;
}
