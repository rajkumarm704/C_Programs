#include<stdio.h>

void generic_swap( void *num1, void *num2, int size)
{
	char temp;
	char *c1 = num1, *c2 = num2;
	int i = 0;

	while( i < size)
	{

	
//		printf("Data1\nnum1:%d, num2:%d\n",*c1,*c2);

		temp = *c1;
		*c1 = *c2;
		*c2 = temp;
//		printf("Data2\nnum1:%d, num2:%d\n",*c1,*c2);
		c1++, c2++, temp++;
/*

		printf("Data1\nnum1:%x, num2:%x\n",*(char *)num1,*(char *)num2);	
		temp = *((char *)num1+i);
		num1 = ((char *)num2+i);
		*((char *)num1+i) = temp;

		printf("Data2\nnum1:%x, num2:%x\n",*(char *)num1,*(char *)num2);	
*/		i++;

	}

}

int main()
{

	int x = 123456, y = 987654;
	float a = 1.2, b = 2.3;
	int arr1[4] = { 1, 2, 3, 4};
	int arr2[4] = { 10, 20, 30, 40};

	printf("Before a:%d, b:%d\n",x,y);
	generic_swap(&x, &y, sizeof(x));
	printf("After a:%d, b:%d\n\n",x,y);

	printf("Before a:%f, b:%f\n",a,b);
	generic_swap(&a, &b, sizeof(a));
	printf("After a:%f, b:%f\n\n",a,b);


	return 0;
}
