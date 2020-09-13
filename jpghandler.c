#include<stdio.h>
#include<string.h>
#include"handlers.h"


int jpg_canHandle(char *filename)
{
	int len;
	char *end;
	printf("checking wether we can handle %s\n",filename);
	len= strlen(filename);
	end = filename +(len-3);
	printf("end = %s\n",end);
	if(strcmp(end, "jpg") == 0)
	{
		return TRUE;
	}
	else
		return FALSE;	
}

int jpg_drawImage(char *filename)
{
		printf("how is this image %s \n",filename);
		return TRUE;
}

int jpg_savefile(char *newfilename)
{
	printf("file save by gif handlers\n ");
	return TRUE;
}

imageHandler jpghandler = {
         jpg_canHandle,
         jpg_drawImage,
         jpg_savefile
};



int _init()
{
        printf("registering jpg handler\n");
        reg_handler(&jpghandler);
        return 0;
}



int _fini(){
	printf("un registering jpg handler \n");
	return 0;
	}
