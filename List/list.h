#ifndef __LIST__H__
#define __LIST__H__

/* Type booléen */
typedef enum
{
	false, //0
	true //1
}Bool;

typedef struct listelement
{
    int value;
    struct listelement *next;
}listelement,*list;

list new_list(void);
Bool is_empty_list(list);
list ajoutDebut(list, int);
list ajoutFin(list, int);
list ajoutPos(list, int,int);
void afficher_list(list);
int list_length(list);
list supprimerDebut(list);
list supprimerFin(list);
list supprimerPos(list, int);
list concat(list, list);
list inverserListe(list);
int nbrOccu(list, int);
list clear_list(list);


#endif