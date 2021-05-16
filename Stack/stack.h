#ifndef __STACK__H__
#define __STACK__H__

	/* Type booléen */
	typedef enum
	{
		false, //0
		true //1
	}Bool;

	
	/* Définition d'une Pile */
	typedef struct StackElement
	{
		int value;
		struct StackElement *next;
	}StackElement, *Stack;
	

	/* Prototypes des fonctions, plus de fonctions que prévue mais les autres fonctions sont à usages personneles,
	   programmant autant que je peux et que je veux durant mon temps libre j'en ai besoin ( ces fonctions étant le fruit de recherches personnelles)
	   pour améliorer mon langage C */
	Stack new_stack(void);
	Bool is_empty_stack(Stack st);
	void print_stack(Stack st);
	Stack push_stack(Stack st, int x);
	Stack pop_stack(Stack st);
	int top_stack(Stack st);
	int stack_length(Stack st);
	Stack clear_stack(Stack st);

#endif