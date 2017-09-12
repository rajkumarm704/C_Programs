#include<stdio.h>

void foo(char *str)
{
	printf("Address:%p\n",str);
}

void bar(void)
{
	char *p = "Hello";
	printf("Address:%p\n",p);
}

void main()
{
	printf("Address:%p\n","Hello");

	bar();

	foo("Hello");

}
