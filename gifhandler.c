#include<stdio.h>
#include<string.h>
#include"handlers.h"

int gif_canHandle(char *filename)
{
	int len;
	char *end;
	printf("checking wether we can handle %s\n",filename);
	len= strlen(filename);
	end = filename +(len-3);
	printf("end = %s\n",end);
	if(strcmp(end, "gif") == 0)
		return TRUE;
	else
		return FALSE;	
}

int gif_drawImage(char *filename)
{
		printf("how is this image %s \n",filename);
		return TRUE;
}

int gif_savefile(char *newfilename)
{
	printf("file save by gif handlers\n ");
	return TRUE;
}


imageHandler gifhandler = {
         gif_canHandle,
         gif_drawImage,
         gif_savefile
};

int _init(){
        printf("registering gif handler\n");
        reg_handler(&gifhandler);
        return 0;
}


int _fini(){
        printf("un registering gif handler \n");
        return 0;
        }

