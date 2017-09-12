#include<stdio.h>
int main()
{

int x=0x53,y=0x33;
int z= x ^ y;
z=~(0x25);

char ch;
ch=0xa2;
ch=ch>>3;

//z=7<<32;	//not correct statement

z=5;
z=1>z;
printf("%x\n",z);

return 0;
}
