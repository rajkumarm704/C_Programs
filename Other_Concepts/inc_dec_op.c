#include<stdio.h>
int main()
{

int x=5,y,z;
y=x++;
z= y--+ - --x;
printf("x:%d y:%d z:%d\n",x,y,z);

return 0;
}
