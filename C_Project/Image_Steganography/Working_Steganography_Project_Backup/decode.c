#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include"types.h"
#include"decode.h"


long int get_count(DecodeStruct *dec_struct)
{
	int i, j = 0;
	uint count = 0, bit, chEnc;

	for( i = 31 ; i >= 0; i-- )
	{
		chEnc = fgetc(dec_struct->encrypted_image_fp);
		bit = chEnc & 1;
		count |= bit << i;
	}

	return count;		
}


Status read_magic_string(DecodeStruct *dec_struct, int count)
{
	int i, j = 0;
	uint data_8byte = 0, mask, bit, chEnc;

	char *user_ms = malloc( sizeof(char) * count );

	while(count--)
	{
		for( i = 7 ; i >= 0; i-- )
		{
			chEnc = fgetc(dec_struct->encrypted_image_fp);
			bit = chEnc & 1;
			data_8byte |= bit << i;
		}

		*(user_ms + j) =  data_8byte;

		data_8byte = 0;
		j++;
	}
	*(user_ms + j) =  '\0';

	if( strcmp(dec_struct->magic_string,user_ms) == 0 )
		return e_success;
	else
		return e_failure;
}

Status read_file_ext(DecodeStruct *dec_struct, int count)
{
	int i, j = 0;
	uint data_8byte = 0, mask, bit, chEnc;
	dec_struct->fdata_ext = malloc( sizeof(char) * count );

	while(count--)
	{
		for( i = 7 ; i >= 0; i-- )
		{
			chEnc = fgetc(dec_struct->encrypted_image_fp);
			bit = chEnc & 1;
			data_8byte |= bit << i;
		}

		*(dec_struct->fdata_ext + j) =  data_8byte;

		data_8byte = 0;
		j++;
	}
	*(dec_struct->fdata_ext + j) =  '\0';
}

Status read_file_data(DecodeStruct *dec_struct, int count)
{
	int i, j = 0;
	uint data_8byte = 0, mask, bit, chEnc;

	sprintf(dec_struct->fdata_fname, "%s.%s", dec_struct->fdata_fname, dec_struct->fdata_ext);

	dec_struct->fdata_fp = fopen(dec_struct->fdata_fname, "w");

	if(dec_struct->fdata_fp == NULL )
		printf("Unable to create %s file.\n\n",dec_struct->fdata_fname );
	else
		printf("File %s was created successfully.\n\n",dec_struct->fdata_fname );


	while(count--)
	{
		for( i = 7 ; i >= 0; i-- )
		{
			chEnc = fgetc(dec_struct->encrypted_image_fp);
			bit = chEnc & 1;
			data_8byte |= bit << i;
		}

		fputc(data_8byte,dec_struct->fdata_fp);

		data_8byte = 0;
		j++;
	}
}



Status perform_decoding(DecodeStruct *dec_struct)
{
	int count;
	Status dec_status;

	fseek(dec_struct->encrypted_image_fp, 54l, SEEK_SET);

	//Get magic string length
	count = get_count(dec_struct);
	dec_status = read_magic_string(dec_struct, count);

	if( dec_status == e_success )	
	{
		printf("Magic string matched. Decoding will start now...\n\n");
		//Get file ext length
		count = get_count(dec_struct);
		read_file_ext(dec_struct, count);

		//Get file data length
		count = get_count(dec_struct);
		read_file_data(dec_struct, count);

		return e_success;
	}
	else
	{
		printf("Magic String not matched. Please enter correct string.\n");
		return e_failure;
	}
	

}
