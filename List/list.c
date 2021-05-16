#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/*Nouvelle liste vide */
list new_list()
{
    return NULL;
}

/* Test si la liste est vide */
Bool is_empty_list(list lst)
{
    if (lst == NULL)
    {
        return true;
    }
    return false;
}

/*Ajoute une valeur au début de la liste */
list ajoutDebut(list l, int y)
{
    list temp;

    temp = malloc(sizeof(listelement));
    if( temp== NULL)
	{
		fprintf(stderr, "Probleme allocation dynamique.\n");
		exit(EXIT_FAILURE);
	}

    temp->value = y;

    if (is_empty_list(temp))
    {
        temp->next = NULL;
    }
    else
    {
        temp->next = l;
    }
    
    return temp;
}

/* Meme chose qu'avant mais pour la fin */
list ajoutFin(list l, int x)
{
    listelement *temp;
    listelement *grappin;

    temp = malloc(sizeof(listelement));

    if( temp== NULL)
	{
		fprintf(stderr, "Probleme allocation dynamique.\n");
		exit(EXIT_FAILURE);
	}

    temp->value = x;
    temp->next = NULL;

    if (is_empty_list(l))
    {
        return temp;
    }

    grappin = l;

    while(grappin->next!=NULL)
    {
        grappin = grappin->next;
    }
    
    grappin->next = temp;

    return l;
}

/* Print la liste */
void afficher_list(list l)
{
    if (is_empty_list(l))
    {
        printf("Rien afficher!");
        exit(EXIT_FAILURE);
    }
    
    while(l!=NULL)
    {
        printf("[%d]",l->value);
        l = l->next;
    }

    printf("\n");
}

/* Retourne la longeur de la liste */
int list_length(list l)
{
    if (is_empty_list(l))
    {
        return 0;
    }

    int lgth = 1;

    while (l->next!=NULL)
    {
        l = l->next;
        lgth++;
    }

    return lgth;
}

/* Supprime le premier élément d'une liste */
list supprimerDebut(list l)
{
    list temp;

    if (is_empty_list(l))
    {
        return new_list();
    }

    temp = l->next;

    free(l);

    return temp;
}

/* Meme chose qu'avant pour la fin */
list supprimerFin(list l)
{
    list temp = l;
    list b = l;
    
    if (is_empty_list(l))
    {
        return new_list();
    }

    
    while (temp->next!=NULL)
    {
        b = temp;
        temp = temp->next;
    }

    b->next = NULL;
    free(temp);

    return l;
}

/* list.remove(index) (même chose) */
list supprimerPos(list l, int index)
{
    int c = 0;
    list temp = l;
    list b = l;

    if (is_empty_list(l)) 
    {
        return new_list();
    }

    // Test de l'indice
    if(list_length(l)-1<index || index<0) 
    {
        printf("Erreur out of range");
        exit(EXIT_FAILURE);
    }

    /*Indice premier ou dernier*/
    if (index == list_length(l)-1)
    {
        l = supprimerFin(l);
        return l;
    }
    if (index == 0)
    {
        l = supprimerDebut(l);
        return l;
    }

    while (c!=index)
    {
        b = temp;
        temp = temp->next;
        c++;
    }

    b->next = temp->next;
    free(temp);

    return l;
}

/* list.add(x,index) */
list ajoutPos(list l, int x, int index)
{
    int c = 0;
    list temp = l,b = l;
    listelement *element;

    element = malloc(sizeof(listelement));

    if (is_empty_list(l)) 
    {
        l = ajoutDebut(l,x);
        return l;
    }

    // Test de l'indice
    if(list_length(l)-1<index || index<0) 
    {
        printf("Erreur out of range");
        exit(EXIT_FAILURE);
    }

    /*Indice premier ou dernier*/
    if (index == list_length(l)-1)
    {
        l = ajoutFin(l,x);
        return l;
    }
    if (index == 0)
    {
        l = ajoutDebut(l,x);
        return l;
    }

    while (c!=index)
    {
        b = temp;
        temp = temp->next;
        c++;
    }

    element->value = x;
    element->next =temp;
    b->next = element;
    
    return l;
}

/* Renvoie une liste de deux listes */
list concat(list l, list p)
{
    list temp = l;

    while (temp->next!=NULL)
    {
        temp = temp->next;
    }

    temp->next = p;

    return l;
}

/* Créer l'inverse d'une liste */
list inverserListe(list l)
{
    list new = new_list(), temp = l;

    while (temp!=NULL)
    {
        new = ajoutDebut(new,temp->value);
        temp = temp->next;
    }

    //l = clear_list(l); //pour supprimer l;
    return new; //Attention new est une nouvelle list, risque de fuis de mémoire.
}

/* Calcul les occurences d'un nombre x */
int nbrOccu(list l, int x)
{
    list temp = l;
    int c = 0;

    while (temp!=NULL)
    {
        if (temp->value==x)
        {
            c++;
        }
        temp = temp->next;
    }

    return c;
}

list clear_list(list l)
{
    while(!is_empty_list(l))
    {
        l = supprimerDebut(l);
    }

    return new_list();
}