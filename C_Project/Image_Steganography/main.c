#include<stdio.h>
#include<stdlib.h>
#include"encode.h"
#include<string.h>
#include"decode.h"

int main(int argc, char *argv[])
{
	system("clear");

/****************************************************/
	EncodeStruct enc_struct;
	enc_struct.text_fp = NULL;
	enc_struct.org_image_fp = NULL;
	enc_struct.dest_image_fp = NULL;
	enc_struct.dest_image_fpi = 0;
/****************************************************/

/****************************************************/
	DecodeStruct dec_struct;
	dec_struct.encrypted_image_fp = NULL;
/****************************************************/

	Status status;

	if( argc < 5 && strcmp(argv[1],"-e") == 0 )
	{
		printf("Invalid arguments.\nPlease execute command in following format\n\n");
		printf("command  <-e> <text filename> <Destination Image Filename> <Source Image Filename>\n\n");
//			   0	   1	     2			     3		             4	    
		return 1;

	}
	else if( argc == 5 && strcmp(argv[1],"-e") == 0 )
	{
/*******************************Encode Data Initialisation*************************************/
		//Save text file name and open the file
		if(argv[2] != NULL)
		{
			enc_struct.text_fname = argv[2];

			enc_struct.file_ext = strchr(enc_struct.text_fname, '.') + 1;

			printf("File Extension:%s\n",enc_struct.file_ext);

			enc_struct.text_fp = fopen(enc_struct.text_fname, "r");

			if(enc_struct.text_fp == NULL )
				printf("Unable to open %s file.\n\n",enc_struct.text_fname );
			else
				printf("File %s was opened successfully.\n\n",enc_struct.text_fname );
		}

		//Save Destination Image file name and open the file
		if(argv[3] != NULL)
		{
			enc_struct.dest_image_fname = argv[3];
			enc_struct.dest_image_fp = fopen(enc_struct.dest_image_fname, "w");

			if(enc_struct.dest_image_fp == NULL )
				printf("Unable to open %s file.\n\n",enc_struct.dest_image_fname );
			else
			printf("File %s was opened successfully.\n\n",enc_struct.dest_image_fname );
		}

		//Save Source Image file name and open the file
		if(argv[4] != NULL)
		{
			enc_struct.org_image_fname = argv[4];
			enc_struct.org_image_fp = fopen(enc_struct.org_image_fname, "r");

			if(enc_struct.org_image_fp == NULL )
				printf("Unable to open %s file.\n\n",enc_struct.org_image_fname );
			else
			printf("File %s was opened successfully.\n\n",enc_struct.org_image_fname );
		}

	}


/*********************************************************************************************/

	else if( argc < 5 && strcmp(argv[1],"-d") == 0 )
	{
		printf("Invalid arguments.\nPlease execute command in following format\n\n");
		printf("command  <-d> <Encrypted Image Filename> <Data Filename> <Password>\n\n");
//			   0	   1		2			3		4
		return 1;
	}
	else if( argc == 5 && strcmp(argv[1],"-d") == 0 )
	{
/*******************************Decode Data Initialisation*************************************/

		//Save Encrypted Image file name and open the file
		if(argv[2] != NULL)
		{

			dec_struct.encrypted_image_fname = argv[2];
			dec_struct.encrypted_image_fp = fopen(dec_struct.encrypted_image_fname, "r");

			if(dec_struct.encrypted_image_fp == NULL )
				printf("Unable to open %s file.\n\n",dec_struct.encrypted_image_fname );
			else
			printf("File %s was opened successfully.\n\n",dec_struct.encrypted_image_fname );

		}

		//Save Encrypted data file name and open the file
		if(argv[3] != NULL)
		{
			dec_struct.fdata_fname = argv[3];
		}

		//Save magic string
		if(argv[4] != NULL)
		{
			dec_struct.magic_string = argv[4];
		}

	}


/**********************************************************************************************/

	if(strcmp(argv[1],"-e") == 0 )
	{
		printf("Encoding\n\n");
		//Perform Encoding
		status = perform_encoding(&enc_struct);

		if( status == e_success )
			printf("Encoding done successfully. Your data is secured ;-)\n");
		else
			printf("There was an error in Encoding process. Your data is not secured :-(\n\n\n");
	}
	else if(strcmp(argv[1],"-d") == 0 )
	{
		printf("Decoding\n\n");
		//Perform Decoding
		status = perform_decoding(&dec_struct);

		if( status == e_success )
			printf("Decoding done successfully. Your data is successfully retrieved ;-)\n");
		else
			printf("There was an error in Decoding process. Your data is not retrieved completely. Data might have corrupted :-(\n\n\n");

	}	

	return 0;
}
