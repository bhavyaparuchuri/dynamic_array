#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>
#include<string.h>
#include <sys/types.h>
#include <unistd.h>
#include "handlers.h"

char *so_array[300];
char filename[100];
char soname[100];
char so_name[300];

int init_handlers(){
	static int i=0,j=1;
	FILE *fp;
	void *soptr;
	fp=fopen("./config.txt","r");
	if(fp==NULL){
		printf("config.txt not found \n");
		return FALSE;
	}
	fgets(so_name,300,fp);
	while(!feof(fp)){
		so_name[strlen(so_name)-1]='\0';
		printf("%d.Loading .. %s\n",j,so_name);
		j++;
		soptr=dlopen(so_name,RTLD_NOW);
		so_array[i]=soptr;
		i++;
		if(soptr == NULL){
			printf("failed to load library\n");
			return FALSE;
		}
		fgets(so_name,300,fp);
	}
	return TRUE;
}

void handleMenuEvent(int choice)
{

	switch (choice){
	case 1:
		printf("Enter file name :");
		scanf("%s",filename);
		vdrawimage(filename);
		break;
	case 2:
		printf("Enter file name :");
		scanf("%s",filename);
		vsavefile(filename);
		break;
	case 4:
		printf("enter the name of so file that you want to remove:\n");
		scanf("%s",soname);	
		unreg_handler(soname);
	}
	printf("---------------------\n");
}

void displayMenu()
{
        int choice;
        while(1){
                printf("1: show image \n");
                printf("2: save image \n");
                printf("3: exit \n");
		printf("4: you want to remove any so file\n");
                printf("choice:");
                scanf("%d",&choice);
                if(choice == 3)
                        exit(0);
                handleMenuEvent(choice);
        }
        
}


int main()
{
	start = (struct node *) malloc(sizeof(struct node));
	ptr=start;
	printf("start : %p\n",start);
	init_handlers();
        displayMenu();
	return 0;
}

