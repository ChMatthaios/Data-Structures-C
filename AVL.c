#include "AVL.h"

int main(){
    struct AVL *root = NULL;

    printf("To dentro:\n");
    root = AVL_Insert(root, 9),  root = AVL_Insert(root, 5), root = AVL_Insert(root, 10);
    root = AVL_Insert(root, 0),  root = AVL_Insert(root, 6), root = AVL_Insert(root, 11);
    root = AVL_Insert(root, -1), root = AVL_Insert(root, 1), root = AVL_Insert(root, 2);

    AVL_PreOrder(root);

    root = AVL_Delete(root, 10);
    printf("\n\nTo dentro meta th diagrafh tou 10.\n");
    AVL_PreOrder(root);

    root = AVL_Delete(root, 6);
    printf("\n\nTo dentro meta th diagrafh tou 6.\n");
    AVL_PreOrder(root);
    return 0;
}