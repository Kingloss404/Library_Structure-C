#ifndef __QUEUE__H__
#define __QUEUE__H__

/* Type booléen */
typedef enum
{
	false, //0
	true //1
}Bool;

/*Definition du corps d'une file*/
typedef struct QueueElement
{
	int value;
	struct QueueElement *next;
}QueueElement, *Queue;

/*Les pointeurs qui ancre le début et la fin de la file*/
typedef struct File
{
    Queue first;
    Queue last;
    int lgth;
}File;

/*les prototypes des fonctions */
File new_queue(void);
Bool is_empty(File);
int top_queue(File);
File push_queue(File, int);
File pop_queue(File);
File clear_queue(File);


#endif