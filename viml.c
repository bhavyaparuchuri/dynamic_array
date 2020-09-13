#include<stdio.h>
#include "handlers.h"
#include <dlfcn.h>
#include<stdlib.h>

extern char *so_array[300];
extern char so_name[300];

extern struct node *start,*ptr;

static int count;


int reg_handler(imageHandler *ih){
	ptr->data=ih;
	printf("ih = %p  %s\n",ih,so_name);
	printf("ptr= %p\n",ptr);
	ptr->next = (struct node *) malloc(sizeof(struct node));
	ptr=ptr->next;
	count++;
	return TRUE;
	}


/* 
	This routine implements request switching logic, it attempts to locate suitable handler to process user request.

	suitable handler is located by traversing through each of the registered handler object in the array(imageHander[] array)           		until compatible object is found.

	on sucess it return offset position of the handler in the array, else -1 on failure.

*/


void unreg_handler(char *soname){
	imageHandler *ih;
	struct node *ptr1;
	int i,handleno = 0;
	ptr=start;
	ih = ptr->data;
	while(ih != NULL){
		printf("%s: Handleno = %d ptr = %p\n",__func__, handleno,ih);
		if(ih->canHandle(soname)){
			ptr1=ptr->next;
			free(ptr);
			ptr->data=(imageHandler *)1;
			if(ptr->data!=NULL){
				ptr->next=ptr1->next;
				ptr->data=ptr1->data;
				}
			dlclose(so_array[handleno]);
			for(i=handleno;i<count;i++){
				so_array[i]=so_array[i+1];
				}
		break;
		}
		handleno++;
		ptr=ptr->next;
		ih=ptr->data;
	}
}


int find_handler(char *filename)
{
	imageHandler *ih;
	int handleno = 0;
	ptr=start;
	ih = ptr->data;
	while(ih != NULL){
		printf("%s: Handleno = %d ptr = %p\n",__func__, handleno,ih);
		if(ih->canHandle(filename)){
			return handleno;
		}
		handleno++;
		ptr=ptr->next;
		ih=ptr->data;
	}
	return -1;
}



int vdrawimage(char *filename)
{
	imageHandler *ih;
        int handleno = 0;
	handleno = find_handler(filename);
        printf("%s: Handleno = %d ptr = %p\n",__func__, handleno,ih);
        if(handleno == -1){
		printf("we can not handle this file\n");
                return FALSE;
		}
	ih=ptr->data;
       	ih->drawImage(filename);
        return TRUE;
}



int vsavefile(char *filename)
{

	imageHandler *ih;
        int handleno = 0;
        handleno = find_handler(filename);
	if(handleno == -1){
               printf("we can not handle this file\n");
               return FALSE;
               }
	ih=ptr->data;
        ih->savefile(filename);
        return TRUE;
}

