#include"types.h"

typedef struct _EncodeStructure
{
	/*	Text file	*/
	FILE *text_fp ;
	char *text_fname;
	char *file_ext;	

	/*	Source Image file	*/
	FILE *org_image_fp ;
	char *org_image_fname;

	/*	Destination Image file	*/
	FILE *dest_image_fp ;
	char *dest_image_fname;
	uint dest_image_fpi;

}EncodeStruct;

//Perform Encoding
Status perform_encoding(EncodeStruct *enc_struct);
/*
//Write data packet into image
Status write_packet(EncodeStruct *enc_struct, char *data );

//Copy source image header to destination image
Status copy_header_bmp_image(EncodeStruct *enc_struct);

//Check file size Function
long int check_text_file_size(EncodeStruct *enc_struct);	

//Check image size Function
long int check_image_file_size(EncodeStruct *enc_struct);

//Write remaining orginal image into dest image
Status copy_remaining_image(EncodeStruct *enc_struct);
*/
