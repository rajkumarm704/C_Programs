#include<stdio.h>
#include<string.h>
#include"encode.h"
#include"types.h"

Status enc_status;
long int char_count, text_fsize, image_fsize;
char data[20] = "";
char magic_string[] = "123";


//Copy source image header to destination image
Status copy_header_bmp_image(EncodeStruct *enc_struct)
{
	uint chOrg, i = 0;

	while( i < 54 )
	{
		chOrg = fgetc(enc_struct->org_image_fp);
		fputc(chOrg, enc_struct->dest_image_fp);
		i++;
	}

	enc_struct->dest_image_fpi = ftell(enc_struct->dest_image_fp);

	if( ftell(enc_struct->dest_image_fp) == 54 && ftell(enc_struct->org_image_fp) == 54 )
		return e_success;
	else 
		return e_failure;
}


//Check file size Function
long int check_text_file_size(EncodeStruct *enc_struct)
{
	long int size;

	fseek(enc_struct->text_fp, 0l, SEEK_END);
	size = ftell(enc_struct->text_fp);

	return size - 1;

}

//Check Original image size Function
long int check_image_file_size(EncodeStruct *enc_struct)
{
	long int size ;

	fseek(enc_struct->org_image_fp, 0l, SEEK_END);
	size = ftell(enc_struct->org_image_fp);

	return size - 1;
}

//Write pixel data into image file
Status write_packet(EncodeStruct *enc_struct, char *data, long int count)
{
	int i, j = 0, pixel_count = 0;
	uint chPkt, chOrgPxl, bitCount;
	int mask, bit;

	//Set FPI of Image file to 54th byte, Header size of .bmp fie is 54
	fseek(enc_struct->org_image_fp, enc_struct->dest_image_fpi, SEEK_SET);


	//First write count to image
	//Run the loop 32 times for 4*8 times
	for( i = 31; i >= 0; i-- )
	{
		//Read ith bit from count
		bitCount = count & ( 1 << i) ;

		//Read 1 pixel from source image file
		chOrgPxl = fgetc(enc_struct->org_image_fp);

		//Create mask to extract a bit from file character
		mask = 1 << i;

		//Extract bit
		bit = bitCount & mask;

		//Shift bit right i times to obtain 1 bit
		bit = bit >> i;

		//Store the bit in image file pixel
		if( bit == 0)
			chOrgPxl &= 0xFE;
		else if( bit == 1 )
			chOrgPxl |= 1;

		//Write the modified pixel into image file; FPI shifted 1 bit right
		fputc(chOrgPxl, enc_struct->dest_image_fp);
	}

	//Run the loop number of bits time the file has
	while( data[j] != '\0' )
	{
		//Read 1 character from packet
		chPkt = data[j];

		//Run the loop 8 times for each character
		for( i = 7; i >= 0; i-- )
		{
			//Read 1 pixel from source image file
			chOrgPxl = fgetc(enc_struct->org_image_fp);

			//Create mask to extract a bit from file character
			mask = 1 << i;

			//Extract bit
			bit = chPkt & mask;

			//Shift bit right i times to obtain 1 bit
			bit = bit >> i;

			//Store the bit in image file pixel
			if( bit == 0)
				chOrgPxl &= 0xFE;
			else if( bit == 1 )
				chOrgPxl |= 1;

			//Write the modified pixel into image file; FPI shifted 1 bit right
			fputc(chOrgPxl, enc_struct->dest_image_fp);
		}
		j++;

//printf("org fpi: %ld\t dest fpi: %ld\n",ftell(enc_struct->org_image_fp), ftell(enc_struct->dest_image_fp) );

		if( ftell(enc_struct->org_image_fp) != ftell(enc_struct->dest_image_fp) )
		{
			printf("Write error...\n");
			break;
		}

	}

	//Update the current image fpi for data continuity
	enc_struct->dest_image_fpi = ftell(enc_struct->dest_image_fp);

	if(enc_struct->dest_image_fpi != 0 )
		return e_success;
	else
		return e_failure;

}

//Write remaining orginal image into dest image
Status copy_remaining_image(EncodeStruct *enc_struct)
{
	int i = 0;
	int chOrg = 1;
	fseek(enc_struct->dest_image_fp, enc_struct->dest_image_fpi, SEEK_SET);
	fseek(enc_struct->org_image_fp, enc_struct->dest_image_fpi, SEEK_SET);

	while( chOrg != EOF )
	{
		chOrg = fgetc(enc_struct->org_image_fp);

		if( chOrg == EOF )
			break;

		fputc( chOrg, enc_struct->dest_image_fp);
	}

	if( ftell(enc_struct->org_image_fp) != ftell(enc_struct->dest_image_fp) )
	{
		printf("**Write error...\n");
		return e_failure;
	}
	else
	{
		printf("Remaming Original image copied to dest image.\nNumber of pixels copied: %ld\n\n", ftell(enc_struct->dest_image_fp) );
		return e_success;
	}

}

//Perform encoding
Status perform_encoding(EncodeStruct *enc_struct)
{
	//Copy source image header to destination image
	enc_status = copy_header_bmp_image(enc_struct);

	if( enc_status == e_success )
		printf("Source image header was copied successfully.\n\n");
	else if( enc_status == e_failure )
		printf("Unable to copy source image header.\n\n");


	//Check Compatibility for encoding
	text_fsize = check_text_file_size(enc_struct);	

	image_fsize = check_image_file_size(enc_struct);

	if( (text_fsize * 8) < (image_fsize*3) )
		printf("File sizes are compatible. Encoding will start now...\n\n");
	else if( (text_fsize * 8) > (image_fsize*3) )
	{
printf("Image file size is lesser than text file size. Encoding cannot be performed. Please supply a bigger size image file.\n\n");
		return 1;
	}

/*******************************************************************************/
	//Write magic string
	long int magic_str_len = strlen(magic_string);
	sprintf(data,"%s", magic_string);
	enc_status = write_packet(enc_struct, data, magic_str_len);

/*******************************************************************************/


/*******************************************************************************/
	//Write file extension
	long int fext_str_len = strlen(enc_struct->file_ext);
	sprintf(data,"%s", enc_struct->file_ext);
	enc_status = write_packet(enc_struct, data, fext_str_len);

/*******************************************************************************/


/*******************************************************************************/
	//Write source file in image
	fseek(enc_struct->text_fp, 0l, SEEK_SET);
	char text_file_buffer[text_fsize];
	fread(text_file_buffer, text_fsize, 1, enc_struct->text_fp);
	text_file_buffer[text_fsize] = '\0';
	enc_status = write_packet(enc_struct, text_file_buffer, text_fsize);

/*******************************************************************************/


/*******************************************************************************/
	//Copy remaining image
	enc_status = copy_remaining_image(enc_struct);

/*******************************************************************************/

	if( enc_status == e_success )
		return e_success;
	else
		return e_failure;
}

