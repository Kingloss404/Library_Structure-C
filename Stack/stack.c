#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

/*Renvoie une pile vide*/
Stack new_stack(void)
{
	return NULL;
}

/*Test si la pile est vide*/
Bool is_empty_stack(Stack st)
{
	if(st == NULL)
		return true;

	return false;
}

/*Empile*/
Stack push_stack(Stack st, int x)
{
	StackElement *element;

	element = malloc(sizeof(*element));

	if(element == NULL)
	{
		fprintf(stderr, "Probleme allocation dynamique.\n");
		exit(EXIT_FAILURE);
	}

	element->value = x;
	element->next = st;

	return element;
}

/*Dépile*/
Stack pop_stack(Stack st)
{
	StackElement *element;

	if(is_empty_stack(st))
	{
		return new_stack();
	}
		
	
	element = st->next;
	free(st);

	return element;
}

/*Affiche la pile*/
void print_stack(Stack st)
{
	if(is_empty_stack(st))
	{
		printf("Rien a afficher, la Pile est vide.\n");
		return;
	}

	while(!is_empty_stack(st))
	{
		printf("[%d]\n", st->value);
		st = st->next;
	}
}

/*Affiche le sommet*/
int top_stack(Stack st)
{
	if(is_empty_stack(st))
	{
		printf("Aucun sommet, la Pile est vide.\n");
		exit(EXIT_FAILURE);
	}

	return st->value;
}

/*Longeur de la Pile*/
int stack_length(Stack st)
{
	int length = 0;

	while(!is_empty_stack(st))
	{
		length++;
		st = st->next;
	}

	return length;
}

/*Vider la mémoire de la pile (comme free mais pour les piles)*/
Stack clear_stack(Stack st)
{
	while(!is_empty_stack(st))
	{
		st = pop_stack(st);
	}
	
	return new_stack();
}