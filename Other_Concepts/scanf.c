#include<stdio.h>
int main()
{
int x,y,z;
char str[100];
/*
printf("Enter values of x y z Ctrl+D\n");
scanf("%d %d %d\n",&x,&y,&z);
printf("x:%d y:%d z:%d\n",x,y,z);

printf("Enter values of x,y,z Ctrl+D\n");
scanf("%d, %d, %d\n",&x,&y,&z);
printf("x:%d y:%d z:%d\n",x,y,z);

printf("Enter values of x y zn Ctrl+D\n");
scanf("Three values are %d %d %d\n",&x,&y,&z);
printf("x:%d y:%d z:%d\n",x,y,z);


printf("Enter time in HH:MM:SS\n");
scanf("%d%*s%d%*s%d",&x,&y,&z);
printf("Time is %d:%d:%d\n",x,y,z);
*/
printf("Enter a string:");
scanf("%[a-z A-Z]",str);
printf("String is %s\n",str);

/*

printf("Enter a string:");
scanf("%[^a-z\n]",str);
printf("String is %s\n",str);

*/

return 0;
}

