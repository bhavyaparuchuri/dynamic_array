#include<stdio.h>
#include<string.h>
#include"handlers.h"


int gif_canHandle(char *filename)
{
	int len;
	char *end;

	int file;
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
	if(canHandle(filename)){
		printf("how is this image %s \n",filename);
		return TRUE;
	}
	else
		return FALSE;
}

int gif_savefile(char *newfilename)
{
	printf("file save by gif handlers\n ");
	return TRUE;
}



int tif_canHandle(char *filename)
{
        int len;
        char *end;

        int file;
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
        if(canHandle(filename)){
                printf("how is this image %s \n",filename);
                return TRUE;
        }
        else
                return FALSE;
}

int tif_savefile(char *newfilename)
{
        printf("file save by gif handlers\n ");
        return TRUE;
}


int jpg_canHandle(char *filename)
{
        int len;
        char *end;

        int file;
        printf("checking wether we can handle %s\n",filename);
        len= strlen(filename);
        end = filename +(len-3);
        printf("end = %s\n",end);
        if(strcmp(end, "jpg") == 0)
                return TRUE;
        else
                return FALSE;
}

int jpg_drawImage(char *filename)
{
        if(canHandle(filename)){
                printf("how is this image %s \n",filename);
                return TRUE;
        }
        else
                return FALSE;
}

int jpg_savefile(char *newfilename)
{
        printf("file save by gif handlers\n ");
        return TRUE;
}
