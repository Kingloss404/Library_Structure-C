#ifndef __LINKED2__H__
#define __LINKED2__H__

/* Type booléen */
typedef enum
{
	false, //0
	true //1
}Bool;

/*Le "noeud d'une liste "*/
typedef struct listnode
{
    int value;
    struct listnode *next;
    struct listnode *before;
}lstnode,*listnode;

/*Liste doublement chainée */
typedef struct dlist
{
    int length;
    struct listnode *debut;
    struct listnode *fin;
}*dlist;

/*Prototypes */
dlist new_dlist(void);
Bool is_empty_dlist(dlist);
dlist add_debut(dlist, int);
dlist add_fin(dlist, int);
void print_dlist(dlist);
void print_idlist(dlist);
void find_node(dlist, int);
dlist delete_nodex(dlist, int);
dlist delete_debut(dlist);
dlist clear_dlist(dlist);

#endif