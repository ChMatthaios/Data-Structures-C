#include "BinTree.h"
#include <stdlib.h>
#include <time.h>

int main(){
    system("color 2");                                          //apla paizw me ta xrwmata tou kwdika
    int e;                                                      //akeraios gia diaxeirish eisodwn kai elements pou mpainoun
    struct BTAr *root = NULL;                                   //dhmiourgw thn riza
    srand(time(0));                                             //ksekinaw tyxaiothta
    for (int i = 0; i < 21; i++)
        e = 1 + rand() % 50, root = BTAInsert(root,e);          //gemizw to dentro me random 20 arithmous

    printf("PreOrder:\t"),      BTAPreOrder(root);              //emfanish preorder
    printf("\nInOrder:\t"),     BTAInOrder(root);               //emfanish inorder
    printf("\nPostOrder:\t"),   BTAPreOrder(root);              //emfanish postorder

    printf("\nStoixeio gia anazhthsh: "), scanf("%d", &e);
    BTASearch(root, e);                                         //anazhtw arithmo sto dentro

    printf("\nPreOrder:\t"),    BTAPreOrder(root);              //emfanish preorder
    printf("\nInOrder:\t"),     BTAInOrder(root);               //emfanish inorder
    printf("\nPostOrder:\t"),   BTAPreOrder(root);              //emfanish postorder

    printf("\n\nStoixeio gia diagrafh: "), scanf("%d", &e);
    root = BTADelete(root, e);                                  //diagrafw stoixeio apo to dentro

    printf("\nPreOrder:\t"),    BTAPreOrder(root);              //emfanish preorder
    printf("\nInOrder:\t"),     BTAInOrder(root);               //emfanish inorder
    printf("\nPostOrder:\t"),   BTAPreOrder(root);              //emfanish postorder

    return 0;
}