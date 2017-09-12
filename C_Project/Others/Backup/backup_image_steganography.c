#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[])
{

	system("clear");

//ch1 => image character
//ch2 => file character

	FILE *fp = NULL, *ip = NULL;
	char *r = "r";
	char *rp = "r+";
	int i, ch1, ch2, pixel_count = 0, char_count = 0;
	int mask, bit, char_temp;

	int magic_pattern_len = strlen(argv[3]);
	int password_len = strlen(argv[4]);
	
	//magic pattern	 =>	argv[3]
	//password	 =>	argv[4]
	
	if( argc < 5 )
	{
		printf("Invalid arguments.\nPlease execute command in following format\n\n");
		printf("command <filename> <image>\n");
		return 1;
	}
	
	fp = fopen(argv[1], r);
	ip = fopen(argv[2], rp);


	//Read all characters from file
	while(  ( ch2 = fgetc(fp) ) != EOF )
	{
		char_count++;
	}

	//Set FPI of file to 0
	fseek(fp, 0L, SEEK_SET);

	printf("Total characters:%d\n",char_count);

	//Set FPI of Image file to 54th byte, Header size of .bmp fie is 54
	fseek(ip, 54L, SEEK_SET);

	//Run the loop number of bits time the file has
	while(  --char_count )
	{
		//Read 1 character from text file
		ch2 = fgetc(fp);

		printf("ch2: %x\n",ch2);

		//Run the loop 8 times for each character
		for( i = 0; i < 8; i++ )
		{
			//Read 1 pixel from image file; FPI shifted 1 bit right
			ch1 = fgetc(ip);

			//Create mask to extract a bit from file character
			mask = 1 << i;

			//Extract bit
			bit = ch2 & mask;

			//Shift bit right i times to obtain 1 bit
			bit = bit >> i;

			printf("bit: %x\t", bit);
			printf("(%d) ch1: %d\t", i, ch1);

			//Store the bit in image file pixel
			ch1 |= bit;

			printf("ch1: %d\n", ch1);

			//Shift FPI to 1 bit left
			fseek(ip, -1l, SEEK_CUR);

			//Write the modified pixel into image file; FPI shifted 1 bit right
//			fputc(ch1, ip);
			fputc(0, ip);
		}
		printf("\n\n");

	}

	pixel_count = ftell(ip) - 54;

	printf("Total pixels:%d\n",pixel_count);
	
	fclose(fp);
	fclose(ip);

	return 0;
}
