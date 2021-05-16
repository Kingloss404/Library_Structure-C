#include <stdio.h>
#include <stdlib.h>
#include "linked2.h"

/*Nouvelle liste vide */
dlist new_dlist()
{
    return NULL;
//On pourrait retourner un 0 au debut et à la fin
//mais cela n'indiquerait pas vraiment que la liste
//est vide, une liste pourrait porter des valeurs 
//nulles mais ne pas être vide
}

Bool is_empty_dlist(dlist l)
{
    if (l == NULL)
    {
        return true;
    }
    return false;
}

/*Ajouter un élément au début de la liste */
dlist add_debut(dlist l, int x)
{
    lstnode *node;
    node = malloc(sizeof(lstnode));
    if (node ==NULL)
    {
        printf("Erreur d'allocation dynamique\n");
        exit(EXIT_FAILURE);
    }

    node->value = x;
    node->next = NULL;
    node->before = NULL;

    if (is_empty_dlist(l))
    {
        l = malloc(sizeof(lstnode));
        if (l ==NULL)
        {
            printf("Erreur d'allocation dynamique\n");
            exit(EXIT_FAILURE);
        }

        l->length = 1;
        l->debut = node;
        l->fin = node;

        return l;
    }

    l->debut->before = node;
    node->next = l->debut;
    l->debut = node;

    l->length++;
    return l;
}

/*Ajouter un element a la fin*/
dlist add_fin(dlist l, int x)
{
    lstnode *node;

    node = malloc(sizeof(lstnode));
    if (node ==NULL)
    {
        printf("Erreur d'allocation dynamique\n");
        exit(EXIT_FAILURE);
    }

    node->value = x;
    node->next = NULL;
    node->before = NULL;

    if (is_empty_dlist(l))
    {
        l = malloc(sizeof(lstnode));
        if (l ==NULL)
        {
            printf("Erreur d'allocation dynamique\n");
            exit(EXIT_FAILURE);
        }

        l->length = 1;
        l->debut = node;
        l->fin = node;
        
        return l;
    }

    l->fin->next = node;
    node->before = l->fin;
    l->fin = node;

    l->length++;
    return l;
}

/*Afficher une liste */
void print_dlist(dlist l)
{
    listnode temp = l->debut;

    if (is_empty_dlist(l))
    {
        printf("Rien a afficher!");
        exit(EXIT_FAILURE);
    }
    while (temp!=NULL)
    {   
        printf("[%d]",temp->value);
        temp = temp->next;
    }
    printf("\n");
    return;
}

/*Affiche l'inverse */
void print_idlist(dlist l)
{
    listnode temp = l->fin;

    if (is_empty_dlist(l))
    {
        printf("Rien a afficher!");
        exit(EXIT_FAILURE);
    }
    while (temp!=NULL)
    {
        printf("[%d]",temp->value);
        temp = temp->before;
    }
    printf("\n");
    return;
}

/*Cherche un element et affiche l'indice du premier
sinon erreur*/
void find_node(dlist l, int x)
{
    listnode temp = l->debut;
    int c = 0;

    if (is_empty_dlist(l))
    {
        printf("Rien a afficher!");
        exit(EXIT_FAILURE);
    }
    while (temp!=NULL)
    {
        if (x == temp->value)
        {
            printf("%d\n",c);
            return;
        }
        temp = temp->next;
        c++;
    }
    printf("La valeur n'existe pas\n");
    return;
}

/*Supprimer le premier element*/
dlist delete_nodex(dlist l, int x)
{
    listnode temp = l->debut;

    if (is_empty_dlist(l))
    {
        printf("Rien a supprimer!");
        exit(EXIT_FAILURE);
    }
    while (temp->next!=NULL)
    {
        if (temp->value == x)
        {
            /* Si liste a un seul element */
            if (l->debut == l->fin)
            {
                free(l);

                return new_dlist();
            }
            /*Si l'element est au debut*/
            else if (temp == l->debut)
            {
                l->debut = temp->next;
                temp->next->before = NULL;
                free(temp);
                return l;
            }
            /*Si l'element est a la fin */
            else if (temp == l->fin)
            {
                l->fin = temp->before;
                temp->before->next = NULL;
                free(temp);
                return l;
            }
            /*Si au milieu */
            else
            {
                temp->next->before = temp->before;
                temp->before->next = temp->next;
                free(temp);
                return l;
            }
        }
        temp = temp->next;
    }
}

/* Enlever un element */
dlist delete_debut(dlist l)
{
    listnode temp = l->debut;

    if(is_empty_dlist(l))
	{
		printf("Rien a supprimer\n");
		return new_dlist();
	}

	if(l->debut == l->fin)
	{
		free(l);
		return new_dlist();
	}

    l->debut = l->debut->next;
    l->debut->before = NULL;

    free(temp);

    l->length--;

    return l;
}

/*Clear de la liste */
dlist clear_dlist(dlist l)
{   
    while (!is_empty_dlist(l))
    {
        l = delete_debut(l);
    }
    return new_dlist();
}