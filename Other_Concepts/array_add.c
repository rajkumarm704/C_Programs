#include<stdio.h>
int main()
{
int arr[5]={1,2,3,4,5};
int *arr_ptr;
arr_ptr=arr;
printf("Size of array is: %x\n",sizeof(arr));
printf("(arr) Address of array is: %p\n",arr);
printf("(arr+1) Address of 2nd element of array is: %p\n",arr+1);
printf("(&arr) Address of array is: %p\n",&arr);
printf("(&arr+1) Address of element next to last element of array is: %p\n",&arr+1);
printf("\nUsing Pointer.\n");
printf("Address of 2nd element array is: %p\n",&arr[1]);
printf("Address of 2nd element of array is: %p\n",arr_ptr+1);

printf("(*(arr_ptr+1))\t Value of 2nd element of array is: %d\n",*(arr_ptr+1));
printf("(*(1+arr_ptr)\t Value of 2nd element of array is: %d\n",*(1+arr_ptr));
printf("(*&arr[1])\t Value of 2nd element of array is: %d\n",*&arr[1]);
printf("(*arr+1))\t Value of 2nd element of array is: %d\n",*(arr+1));
printf("(1[arr])\t Value of 2nd element of array is: %d\n",1[arr]);
printf("(1[arr_ptr])\t Value of 2nd element of array is: %d\n",1[arr_ptr]);
return 0;
}
