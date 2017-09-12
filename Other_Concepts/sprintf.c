#include<stdio.h>
int main()
{
int ret=124;
char ch='A';
float fnum=12.35;
char str[] ="Raj kumar";
char final_string[100];

sprintf(final_string,"%d %c %f %s\n",ret,ch,fnum,str);
printf("%s\n",final_string);

return 0;
}

