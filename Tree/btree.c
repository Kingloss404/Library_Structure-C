#include "btree.h"

/* Creation d'un arbre binaire a un element */
Btree new_tree(int x)
{
    eBtree *tree = malloc(sizeof(eBtree));
    if (tree == NULL)
    {
        printf("Erreur allocation dynmique");
    }

    tree->node = x;
    tree->ltree = NULL;
    tree->rtree = NULL;
    tree->ptree = NULL;

    return tree;
}

/* Vider la mémoire */
void clear_tree(Btree tree)
{
    if (tree == NULL)
    {
        return;
    }

    clear_tree(tree->ltree);
    clear_tree(tree->rtree);

    free(tree);
    tree = NULL;
}

/* Methode plus générale pour la création et l'insertion */
Btree join_tree(int node, Btree left, Btree right)
{
    Btree tree = new_tree(node);

    tree->ltree = left;
    tree->rtree = right;

    if (left != NULL)
    {
        left->ptree = tree;
    }
    if (right != NULL)
    {
        right->ptree = tree;
    }

    return tree;
}

void print_ABR(Btree tree)
{
    if (tree == NULL)
    {
        printf("Rien a afficher");
        return;
    }
    if (tree->ltree != NULL)
    {
        print_ABR(tree->ltree);
    }

    printf("%d ", tree->node);
    if (tree->rtree != NULL)
    {
        print_ABR(tree->rtree);
    }
}

void inserer_ABR(Btree tree, int x)
{
    if (tree->node == x)
    {
        return;
    }
    if (x < tree->node)
    {
        if (tree->ltree == NULL)
        {
            Btree tr = new_tree(x);
            tree->ltree = tr;
            tr->ptree = tree;
        }
        inserer_ABR(tree->ltree, x);
    }
    if (x > tree->node)
    {
        if (tree->rtree == NULL)
        {
            Btree tr = new_tree(x);
            tree->rtree = tr;
            tr->ptree = tree;
        }
        inserer_ABR(tree->rtree, x);
    }
}

Bool rechercher_ABR(Btree tree, int x)
{
    if (tree == NULL)
    {
        return false;
    }
    if (tree->node == x)
    {
        return true;
    }

    if (x < tree->node)
    {
        return rechercher_ABR(tree->ltree, x);
    }

    if (x > tree->node)
    {
        return rechercher_ABR(tree->rtree, x);
    }
}

Bool rechercher_AB(Btree tree, int x)
{
    if (tree->node == x)
    {
        return true;
    }
    if (tree->ltree != NULL)
    {
        return rechercher_AB(tree->ltree, x);
    }
    if (tree->rtree != NULL)
    {
        return rechercher_AB(tree->rtree, x);
    }

    return false;
}

int rechercher_Min(Btree tree)
{
    if (tree == NULL)
    {
        printf("Rien à chercher");
        exit(EXIT_FAILURE);
    }
    if (tree->ltree == NULL)
    {
        return tree->node;
    }

    return rechercher_Min(tree->ltree);
}

int rechercher_Max(Btree tree)
{
    if (tree == NULL)
    {
        printf("Rien à chercher");
        exit(EXIT_FAILURE);
    }
    if (tree->rtree == NULL)
    {
        return tree->node;
    }

    return rechercher_Max(tree->rtree);
}
Btree pointeur_rechercher_ABR(Btree tree, int x)
{
    if (tree == NULL)
    {
        return NULL;
    }
    if (tree->node == x)
    {
        return tree;
    }

    if (x < tree->node)
    {
        return pointeur_rechercher_ABR(tree->ltree, x);
    }

    if (x > tree->node)
    {
        return pointeur_rechercher_ABR(tree->rtree, x);
    }
}

Btree pointeur_rechercher_Min(Btree tree)
{
    if (tree == NULL)
    {
        return tree;
    }
    if (tree->ltree == NULL)
    {
        return tree;
    }

    return pointeur_rechercher_Min(tree->ltree);
}

Bool is_root(Btree tree)
{
    if (tree->ptree == NULL)
    {
        return true;
    }
    return false;
}

Bool is_left(Btree tree)
{
    if (tree->ptree->ltree == tree)
    {
        return true;
    }
    return false;
}

Bool is_right(Btree tree)
{
    if (tree->ptree->rtree == tree)
    {

        return true;
    }
    return false;
}

Bool is_leaf(Btree tree)
{
    if (tree->ltree == NULL && tree->rtree == NULL)
    {
        return true;
    }
    return false;
}

Btree supprimer_ABR(Btree tree, int x)
{
    Btree element = pointeur_rechercher_ABR(tree, x);
    Btree min = pointeur_rechercher_Min(element->rtree);
    if (element == NULL)
    {
        printf("Rien a supprimer");
        exit(EXIT_FAILURE);
    }

    if (is_root(element))
    {
        Btree temp = tree;
        min->ltree = tree->ltree;
        temp = temp->rtree;
        free(tree);
        tree = NULL;
        return temp;
    }

    if (is_leaf(element))
    {
        if (is_left(element))
        {
            free(element);
            element->ptree->ltree = NULL;
        }

        if (is_right(element))
        {
            free(element);
            element->ptree->rtree = NULL;
        }

        return tree;
    }
    else
    {
        Btree temp = element;
        min->ltree = element->ltree;
        temp = temp->rtree;
        if (is_left(element))
        {
            free(element);
            element->ptree->ltree = temp;
        }

        if (is_right(element))
        {
            free(element);
            element->ptree->rtree = temp;
        }
        element = NULL;
        return tree;
    }
}