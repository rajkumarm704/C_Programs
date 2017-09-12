#include<stdio.h>
int main()
{
	int i,j,k,l,result;
	i=j=k=l=0;
	
	result=i++- - --j;

	printf("Result is %d \n",result);

	return 0;
}
