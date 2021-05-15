#include "btree.h"

int main(void)
{
    Btree tree = new_tree(3);

    inserer_ABR(tree, 6);
    inserer_ABR(tree, 5);
    inserer_ABR(tree, 58);
    inserer_ABR(tree, 22);
    inserer_ABR(tree, 84);
    inserer_ABR(tree, 0);
    inserer_ABR(tree, -3);
    inserer_ABR(tree, -4);
    inserer_ABR(tree, -1);
    inserer_ABR(tree, 1);
    
    printf("%d",rechercher_ABR(tree, 5));
    Btree hello = supprimer_ABR(tree, 5);
    

    print_ABR(hello);
    clear_tree(tree);
    return -1;
}