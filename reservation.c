#include "reservation.h"

void reserveAndPrint(RBT* rbt, int key)
{
    printf("before insert ID print tree:\n");
    print_bst1(rbt);
    int insertFlag=tree_insert(rbt,key);
    if(insertFlag)
    {
        printf("after insert ID print tree:\n");
        print_bst1(rbt);
    }
}

void deleteAndPrint(RBT* rbt, int key)
{
   
    printf("before delete ID print tree :\n");
    print_bst1(rbt);
    Node *deleteNode = NULL;

    deleteNode = tree_searchr(rbt->root, key);
    if (deleteNode->key != key)
    {
        printf("                                        ");
        printf("The reservation ID is not existed\n");
        printf("\n");
    }

    else
    {
        tree_delete(rbt,key);
        printf("after delete ID print tree:\n");
        print_bst1(rbt);
        printf("\n");
    }
      
    
}