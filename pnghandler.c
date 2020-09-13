#include<stdio.h>
#include<string.h>
#include"handlers.h"

int png_canHandle(char *filename)
{
	int len;
	char *end;
	printf("checking wether we can handle %s\n",filename);
	len= strlen(filename);
	end = filename +(len-3);
	printf("end = %s\n",end);
	if(strcmp(end, "png") == 0)
		return TRUE;
	else
		return FALSE;	
}

int png_drawImage(char *filename)
{
		printf("how is this image %s \n",filename);
		return TRUE;
}

int png_savefile(char *newfilename)
{
	printf("file save by png handlers\n ");
	return TRUE;
}


imageHandler pnghandler = {
         png_canHandle,
         png_drawImage,
         png_savefile
};

int _init(){
        printf("registering png handler\n");
        reg_handler(&pnghandler);
        return 0;
}


int _fini(){
        printf("un registering png handler \n");
        return 0;
        }

