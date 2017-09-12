#include"types.h"

typedef struct _DecodeStructure
{
	/*	Text file	*/
	FILE *fdata_fp ;
	char *fdata_fname;
	char *fdata_ext;	
	
	/*	Source Image file	*/
	FILE *encrypted_image_fp ;
	char *encrypted_image_fname;

	char *magic_string;

}DecodeStruct;

//Perform Encoding
Status perform_decoding(DecodeStruct *dec_struct);

