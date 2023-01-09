/**
 * Swros einai mia eidikh tree-like domh, opou to dentro einai ena dyadiko gemato dentro
 * Mporei na einai dyo typwn:
 *  (a) MaxHeap: H riza tha prepei na einai to megalytero stoixeio apo ola ta paidia tou
 *       100
 *     /     \
 *    40     50
 *   /  \   /  \
 *  10  15 50  40
 *
 *  (b) MinHeap: H riza tha prepei na einai to mikrotero stoixeio apo ola ta paidia tou
 *       10
 *     /     \
 *    15     30
 *   /  \   /  \
 *  40  50 100 40
 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*************************************************************
 *                   ESTW INTEGER MIN-HEAP                   *
 *************************************************************/

void MinHeap_Swap(int *x, int *y){                                  //antallagh dedomenwn
    int tmp = *x;                                                   //dhlwnw temp metablhth kai
    *x = *y, *y = tmp;                                              //kanw tis allages
}

struct MinHeap{                                                     //domh min heap
    int *Pin, cap, megethos;                                        //h opoia periexei enan pinaka, xwrhtikothta kai trexwn megethos
};

struct MinHeap *MinHeap_Create(int cap){                            //dhmiourgei thn heap me dotheisa xwrhtikothta
    struct MinHeap *MH = NULL;                                      //dhmiourgei mia metablhth typou struct
    MH = (struct MinHeap *) malloc(sizeof(struct MinHeap));         //kanei allocate to xwro
    MH->cap = cap;                                                  //thetei xwrhtikothta
    MH->megethos = 0;                                               //trexwn megethos
    MH->Pin = (int *) malloc(MH->cap * sizeof(int));                //kai dhmiourgei ton pinaka
    return MH;                                                      //epistrefei thn metablhth typou struct
}

int MinHeap_parent(int i)               {return (i - 1) / 2;}       //epistrefei ton gonio tou branch
int MinHeap_left(int i)                 {return 2*i + 1;}           //epistrefei ta aristera paidia
int MinHeap_right(int i)                {return 2*i + 2;}           //epistrefei ta deksia paidia
int MinHeap_getMin(struct MinHeap *MH)  {return MH->Pin[0];}        //epistrefei to mikrotero stoixeio

void MinHeap_meiwshElem(struct MinHeap *MH, int i, int elem){       //meiwnei thn timh enos stoixeiou kai to allazei thesh
    MH->Pin[i] = elem;                                              //vazw sth thesh to stoixeio
    while (i != 0 && MH->Pin[MinHeap_parent(i)] > MH->Pin[i]){      //oso o gonios einai > tou paidiou kai to i diaforo tou 0
        MinHeap_Swap(&MH->Pin[i], &MH->Pin[MinHeap_parent(i)]);     //allazw ta stoixeia se gonio kai paidia
        i = MinHeap_parent(i);                                      //kai kanw to i ton gonio gia na koinithw sthn heap
    }
}

void MinHeap_heapify(struct MinHeap *MH, int i){                    //episkeftetai olous tous nodes apo katw pros ta panw kai
                                                                    //otan ftanoume se komvo gonio ta apo katw tou einai hdh heap
    int l = MinHeap_left(i);                                        //kratame to aristero kai deksi paidi
    int r = MinHeap_right(i);
    int mikrotero = i;                                              //kai to i pou perase o xrhsths
    if (l < MH->megethos && MH->Pin[l] < MH->Pin[i])                //an to aristero paidi einai < apo to megethos tou pinaka kai h thesh tou paidiou einai mikroterh apo thn trexousa
        mikrotero = l;                                              //tote mikrotero ginetai to aristero
    if (r < MH->megethos && MH->Pin[r] < MH->Pin[mikrotero])        //an to deksi paidi einai < apo to megethos tou pinaka kai h thesh tou paidiou einai mikroterh apo thn mikroterh
        mikrotero = r;                                              //tote mikrotero ginetia to deksi
    if (mikrotero != i){                                            //an h mikroterh thesh einai diaforo tou trexontos i
        MinHeap_Swap(&MH->Pin[i], &MH->Pin[mikrotero]);             //tote allazw ta stoixeia
        MinHeap_heapify(MH, mikrotero);                                 //kai ksanakalw ton eauto ths me dedomeno to mikrotero pou eftiaksa
    }
}

int MinHeap_removeMin(struct MinHeap *MH){                          //diagrafei to mikrotero stoixeio ths heap
    if (MH->megethos <= 0)  return INT_MAX;                         //an einai kenh tote termatizei
    if (MH->megethos == 1){                                         //an yparxei ena stoixeio
        MH->megethos--;                                             //tote meiwnei to megethos
        return MH->Pin[0];                                          //kai afairei auto to stoixeio
    }
    int root = MH->Pin[0];                                          //alliws krataw ws riza to prwto stoixeio tou pinaka
    MH->Pin[0] = MH->Pin[MH->megethos - 1];                         //vazw sth thes tou to epomeno
    MinHeap_heapify(MH, 0);                                         //kai kalw th heapify gia na epanaferw tis theseis
    return root;
}

void MinHeap_deleteElem(struct MinHeap *MH, int i){                 //diagrafei to stoixeio pou tha tou dwsei o xrhsths
    MinHeap_meiwshElem(MH, i, INT_MIN);                             //meiwnei th thesh tou kalwntas thn meiwshELem kai ftiaxnei tis theseis
    MinHeap_removeMin(MH);                                          //kai to diagrafei apo thn heap
}

void MinHeap_Insert(struct MinHeap *MH, int elem){                  //prosthetei dedomena mesa sth heap
    if (MH->megethos == MH->cap){                                   //an exoume osa stoixeia mporei na xwresei emfanizei mhnyma lathous kai termatizei
        printf("Overflow.\n");
        return;
    }
    MH->megethos++;                                                 //alliws auksanei to megethos kata ena
    int i = MH->megethos - 1;                                       //thetei kainourio i
    MH->Pin[i] = elem;                                              //vazei sth thesh to stoixeio
    while (i != 0 && MH->Pin[MinHeap_parent(i)] > MH->Pin[i]){      //kai proxwraei mesa sth heap xrhsimopoiontas tou goneis stoixeia
        MinHeap_Swap(&MH->Pin[i], &MH->Pin[MinHeap_parent(i)]);     //allazei ta stoixeia meta thn prosthikh
        i = MinHeap_parent(i);                                      //kai kanei to i na parei th thesh tou gonea
    }
}