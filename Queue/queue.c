#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

/*Creation d'une file vide*/
File new_queue()
{
    File file;

    file.first = NULL;
    file.last = NULL;
    file.lgth = 0;

    return file;
}

/*Test si la file est vide*/
Bool is_empty(File q)
{
    if (q.first==NULL && q.last==NULL)
    {
        return true;
    }
    return false;
}

/*Donner la tete de la file */
int top_queue(File q)
{   
    if (is_empty(q))
    {
        printf("La pile est vide !");
        exit(EXIT_FAILURE);
    }
    return q.first->value;
}

/*Enfiler la file */
File push_queue(File q, int x)
{
    Queue transition;

    transition = malloc(sizeof(Queue));
    if(transition == NULL)
	{
		fprintf(stderr, "Probleme allocation dynamique.\n");
		exit(EXIT_FAILURE);
	}

    transition->value = x;
    transition->next = NULL;

    if (is_empty(q))
    {
        q.first = transition;
        q.last = transition;
    }
    else 
    {
        q.last->next = transition;
        q.last = transition;
    }

    q.lgth++;

    return q;
}

/*Defiler une file */
File pop_queue(File q)
{
    Queue tampon = q.first;

    if (is_empty(q))
    {
        return new_queue();
    }
    
    if (q.first == q.last)
    {
        q.first = NULL;
        q.last = NULL;
    }
    else
    {
        q.first = q.first->next;
    }
    
    free(tampon);
    q.lgth--;

    return q;
}

/* Libere la mémmoire à la fin d'utilisation */
File clear_queue(File q)
{
    while(!is_empty(q))
    {
        q = pop_queue(q);
    }
    return new_queue();
}