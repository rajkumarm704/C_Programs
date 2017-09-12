#include<stdio.h>
int main()
{
while(1)
{

	int a,n,d,n_copy,ap,gp,hp,i;
	printf("Enter first term, number of terms and difference for ap: ");
	scanf("%d %d %d",&a,&n,&d);
	n_copy=n;

	//Clear any characters from buffer
	while(getchar() != '\n');

	//Print AP
	printf("AP is: ");
	
	//Calculate AP terms
	for(i=1;i<=n_copy;i++)
	{
		ap=a+(i-1)*d;
		printf(" %d, ",ap);
	}
	printf("\n");

	//Print GP
	printf("GP is: ");
	
	int temp_pow=1,j;
	
	//Print GP
	for(i=0;i<n_copy;i++)
	{
		for(j=0;j<i;j++)
		{
			temp_pow=temp_pow*d;
		}
		
		gp=a*temp_pow;
		printf(" %d, ",gp);
	}
	printf("\n");

	//Print AP
	printf("HP is: ");
	
	//Calculate AP terms
	for(i=1;i<=n_copy;i++)
	{
		ap=a+(i-1)*d;
		printf(" %f, ",(float)1/ap);
	}
	printf("\n");

	//Ask user for options
	printf("Do you want to continue(Y/N):");
	char ch=getchar();
	while(getchar() != '\n');
	if((ch == 'N' || ch == 'n'))
	{
		break;
	}


}
return 0;
}
