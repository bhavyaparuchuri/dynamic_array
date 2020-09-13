#include<stdio.h>
#include<string.h>
#include"handlers.h"


int tif_canHandle(char *filename)
{
	int len;
	char *end;
	printf("checking wether we can handle %s\n",filename);
	len= strlen(filename);
	end = filename +(len-3);
	printf("end = %s\n",end);
	if(strcmp(end, "tif") == 0)
		return TRUE;
	else
		return FALSE;	
}

int tif_drawImage(char *filename)
{
		printf("how is this image %s \n",filename);
		return TRUE;
}

int tif_savefile(char *newfilename)
{
	printf("file save by gif handlers\n ");
	return TRUE;
}


imageHandler tifhandler = {
        tif_canHandle,
        tif_drawImage,
        tif_savefile
};
int _init(){
        printf("registering tif handler\n");
        reg_handler(&tifhandler);
        return 0;
}


int _fini(){
        printf("un registering tif handler \n");
        return 0;
        }

