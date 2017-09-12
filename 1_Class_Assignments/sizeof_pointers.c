#include<stdio.h>
int main()
{

	int *iptr;
	char *cptr;
	long *lptr;
	printf("*ipt:%d\t*cptr:%d\t*lptr:%d\n",sizeof(*iptr),sizeof(*cptr),sizeof(*lptr));
	if(sizeof(lptr)==sizeof(cptr))
		printf("All pointers have same size.\n");
	else
		printf("Not all pointers have same size.\n");		
	return 0;
}
