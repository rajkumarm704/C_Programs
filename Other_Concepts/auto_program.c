#include<stdio.h>
int main()
{
char a,b;
while(scanf("%c%*c%c%*c",&a,&b)!=EOF)
printf("a:%c, b:%c\n",a,b);

return 0;
}
