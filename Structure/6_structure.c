#include<stdio.h>
#include<stdlib.h>

#pragma pack(1)
	
struct Group1
{
	int id;
	char name;
};

struct Group2
{
	char name;
	char address;
	int id;

};


int main()
{

	system("clear");
	struct Group1 g1;
	struct Group2 g2;

	printf("Size of Group1: %ld\n", sizeof(struct Group1) );
	printf("Address of g1.id: %p\n", &g1.id );
	printf("Address of g1.name: %p\n", &g1.name );

	printf("Size of Group2: %ld\n", sizeof(struct Group2) );
	printf("Address of g2.name: %p\n", &g2.name );
	printf("Address of g2.id: %p\n", &g2.id );
	printf("Address of g2.address: %p\n", &g2.address );


	return 0;
}
