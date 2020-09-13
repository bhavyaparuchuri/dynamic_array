#include<stdio.h>
#include<string.h>
#include"handlers.h"

int mpg_canHandle(char *filename)
{
	int len;
	char *end;
	printf("checking wether we can handle %s\n",filename);
	len= strlen(filename);
	end = filename +(len-3);
	printf("end = %s\n",end);
	if(strcmp(end, "mpg") == 0)
		return TRUE;
	else
		return FALSE;	
}

int mpg_drawImage(char *filename)
{
		printf("how is this image %s \n",filename);
		return TRUE;
}

int mpg_savefile(char *newfilename)
{
	printf("file save by mpg handlers\n ");
	return TRUE;
}


imageHandler mpghandler = {
         mpg_canHandle,
         mpg_drawImage,
         mpg_savefile
};

int _init(){
        printf("registering mpg handler\n");
        reg_handler(&mpghandler);
        return 0;
}


int _fini(){
        printf("un registering mpg handler \n");
        return 0;
        }

