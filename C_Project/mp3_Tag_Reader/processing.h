#include"types.h"

Status validate_arguments(Mp3DataStruct *mp3_struct, int argc, char *argv[]);

Status perform_processing(Mp3DataStruct *mp3_struct);

Status find_tags(Mp3DataStruct *mp3_struct);

Status extract_album_art(Mp3DataStruct *mp3_struct);

