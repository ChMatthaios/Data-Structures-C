#include "Map.h"

int main(){
    struct Map *M = newNode(1);                             //dhmiourgw ton komvo
    MInsert(&M, 11), MInsert(&M, 21), MInsert(&M, 31);      //vazw tis times sot Map
    printf("To megethos tou Map einai: %d\n", MSize(M));    //emfanizw megethos
    MDelete(&M, 21);                                        //diagrafw to teleutaio pou mphke
    printf("To megethos tou Map einai: %d\n", MSize(M));
    MPrint(M);                                              //emfanizw to Map
    MClear(&M);                                             //diagrafw olo to Map
    printf("To megethos tou Map einai: %d\n", MSize(M));
    free(M);                                                //eleutherwnw mnhmh
    return 0;
}