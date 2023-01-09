/**
 * Maps einai domes apothikeushs dedomenwn oi opoies kratane dyo dedomena
 * gia kathe eggrafh. Pragma pou shmainei oti krataei ena kleidi kai ena element
 * to kleidi einai monadiko kai den mporei na einai diplotypo alla ta elements
 * mporoun na einai oti theloun. Einai List type domh h opoia den exei fix megethos
 * apla prosthetoume kai afairoume dedomena kata to dokoun.
 */
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

/**********************************************************
 *            ESTW MAP TYPOU <INTEGER, INTEGER>           *
 **********************************************************/

 int KeyCount = 1;                                                  //o metrhths gia ta kleidia

struct Map{                                                         //domh me onoma Map
    int key, elem;                                                  //krataei monadiko kleidi kai stoixeio
    struct Map *next;                                               //kathws kai ton komvo gia to epomeno stoixeio
};

struct Map *newNode(int elem){                                      //dhmiourgei kommo gia th stoiva
    struct Map *mapNode = NULL;                                     //arxikopoihsh kombou
    mapNode = (struct Map*) malloc(sizeof(struct Map));
    mapNode->key = KeyCount++;                                      //aukshsh kleidiou
    mapNode->elem = elem;                                           //vazw o elem mesa sth stoiva
    mapNode->next = NULL;                                           //thn kanw teleutaio kombo ths stoivas
    return mapNode;
}

void MInsert(struct Map **M, int elem){                             //prosthetei stoixeio sto telos tou Map
    struct Map *mapNode = newNode(elem);                            //dhmiourgw neo komvo
    struct Map *last = *M;                                          //thewrw os teleutaio to M
    if (*M == NULL){                                                //an einai keno kane to stoixeio ws M tou
        *M = mapNode;
        return;
    }
    while (last->next != NULL)                                      //alliws proxwraw mexri na vrw to teleutaio
        last = last->next;
    last->next = mapNode;                                           //allazw to next tou prwhn teleutaiou na deixnei sto neo
    printf("Prostethike stoixeio sto Map.\n");
}

int MSize(struct Map *M){                                           //epistrefei to megethos tou Map
    if (M == NULL)  return 0;                                       //an den exei tipota mesa epistrefei 0
    else            return 1 + MSize(M->next);                      //alliws kalei ton eauto ths prosthetontas 1
}

void MDelete(struct Map **M, int e){                                //diagrafei ton komvo pou periexei to stoixeio pou thelw na diagrapsw
    struct Map *tmp = *M, *prev;                                    //krataw to head node
    if (tmp != NULL && tmp->elem == e){                             //an to head den einai null kai periexei to stoixeio pou thelw na diagrapsw
        *M = tmp->next;                                             //allazw to head
        free(tmp);                                                  //eleutherwnw to palio head
        return;
    }
    while (tmp != NULL && tmp->elem != e){                          //psaxnw to stoixeio sth lista
        prev = tmp;                                                 //gia na kinithw allazw thn timh tou prev me thn epomenh gia na "kinoumai" sth lista
        tmp = tmp->next;                                            //kai proxwraw sto epomeno
    }
    if (tmp == NULL)                                                //to stoixeio den vrethike
        return;
    prev->next = tmp->next;                                         //vgazw to stoixeio apo th lista
    free(tmp);                                                      //eleutherwnw mnhmh
    printf("Afairethike stoixeio apo to Map.\n");
}

void MClear(struct Map **M){                                        //diagrafei olh th lista
    struct Map *trexwn = *M, *epomenos;                             //krataw tis theseis pou vriskomai
    while (trexwn != NULL){                                         //mexri na teleiwsei h lista
        epomenos = trexwn->next;                                    //proxwraw stis theseis
        free(trexwn);                                               //katharizw ton trexwn
        trexwn = epomenos;                                          //epomenh thesh
    }
    *M = NULL;                                                      //mhdenizw to head
    printf("Diagrafhke olo to Map.\n");
}

void MPrint(struct Map *M){                                         //emfanish listas
    puts("To Map mou:");
    while(M != NULL)                                                //oso yparxoun stoixeia
        printf(" <%02d,%02d> \n", M->key, M->elem), M = M->next;    //kai kalei ton deikth gia to epomeno wste na allaksei timh
}