#define TRUE 1
#define FALSE 0;

typedef struct{
	int (*canHandle) (char *);
	int (*drawImage) (char *);
	int (*savefile)(char *);
}imageHandler;

struct node{
             imageHandler *data;
             struct node *next;
        }; 

struct node *start, *ptr;



int vdrawimage(char *);
int vsavefile(char *);

extern imageHandler *imagehandlers[];

int reg_handler(imageHandler *);
//void unreg_handler(int );
void unreg_handler(char *soname);
