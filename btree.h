#ifndef __BTREE__H__
#define __BTREE__H__

#include <stdio.h>
#include <stdlib.h>

/* Type booléen */
typedef enum
{
	false, //0
	true //1
}Bool;

/* Compositon d'un arbre */
typedef struct eBtree
{
    int node;
    struct eBtree *ltree;
    struct eBtree *rtree;
    struct eBtree *ptree;//Utile pour faire des tests ou faciliter certaine récuesivité
}eBtree, *Btree;

Btree new_tree(int);//creer un noeud
void clear_tree(Btree);//free de malloc
Btree join_tree(int, Btree, Btree);//relie les noeuds entre eux pour creer un arbre
void print_ABR(Btree);//affiche l'arbre en ordre croissant
void inserer_ABR(Btree, int);//ajoute un élement à l'arbre
Bool rechercher_ABR(Btree, int);//recherche l'ABR
Bool rechercher_AB(Btree, int);//recherche l'AB
int rechercher_Min(Btree);
int rechercher_Max(Btree);
Btree pointeur_rechercher_ABR(Btree, int);//aide pour supprimer
Btree pointeur_rechercher_Min(Btree);//aide pour supprimer
/* Test pour faciliter la fonction supprimer */
Bool is_root(Btree);
Bool is_left(Btree);
Bool is_right(Btree);
Bool is_leaf(Btree);
/* Supprimer un element de l'arbre */
Btree supprimer_ABR(Btree, int);
#endif