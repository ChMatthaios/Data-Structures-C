/**
 * H oura einai mia domh apothikeushs opws kai h stoiva h opoia epitrepei
 * apothikeush kai epeksergasia dedomenwn kanontas kapoies vasikes leitourgies:
 *  a) Enqueue: Vazei dedomena sthn oura
 *  b) Dequeue: Logo tou FIFO(First In First Out) to na vgazei dedomena shmainei
 *              oti tha vgoun opws mphkan
 *  c) Front  : epistrefei to "mprostino" dedomeno ths ouras
 *  d) Rear   : epistrefei to "teleutaio" dedomeno ths ouras
 */

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

/**********************************************
 *          ESTW INT OYRA - PINAKES           *
 **********************************************/

struct Queue_Array{
    int Qfront, Qrear, Qsize, Qcap, *Pin;                               //domh queue h opoia krataei to mprostino, to teleutaio stoixeio, to megethos, ton pinaka kai th xwrhtikothta
};

struct Queue_Array *QCreate_Array(int cap){                             //dhmiourgei thn queue me sygkekrimenh xwhrtikothta kai thn arxikopoiei me 0
    struct Queue_Array *Q = NULL;
    Q = (struct Queue_Array *) malloc(sizeof(struct Queue_Array));      //arxikopoihsh desmeush mnhmhs gia thn queue
    Q->Qcap = cap;                                                      //orizw xwrhtikothta
    Q->Qfront = Q->Qsize = 0;                                           //orizw to mprostino stoixeio
    Q->Qrear = cap - 1;                                                 //meiwnw th xwrhtikothta
    Q->Pin = (int *) malloc(Q->Qcap * sizeof(int));                     //dhmiourgw ton pinaka
    return Q;
}

int isFull_Array(struct Queue_Array *Q){return Q->Qsize == Q->Qcap;}    //epistrefei an einai gemath h oxi h Queue
int isEmpty_Array(struct Queue_Array *Q){return Q->Qsize == 0;}         //epistrefei an einai adeia h oxi h queue

void Enqueue_Array(struct Queue_Array *Q, int elem){                    //prosthetei dedomeno sthn queue
    if (isFull_Array(Q))                                                //elegxos an einai gemath
        return;
    Q->Qrear = (Q->Qrear + 1) % Q->Qcap;                                //auksanei to rear se sxesh me thn xwrhtikothta
    Q->Pin[Q->Qrear] = elem;                                            //vazei to dedomeno sthn queue
    Q->Qsize = Q->Qsize + 1;                                            //auksanei to megethos kata ena
    printf("To stoixeio mphke sthn Oura.\t");
}

void Dequeue_Array(struct Queue_Array *Q){                              //afairei ena stoixeio apo thn oura FIFO
    if (isEmpty_Array(Q))                                               //elegxei an einai adeia
        return;
    int elem = Q->Pin[Q->Qfront];                                       //pianoume ot prwto stoixeio ths ouras
    Q->Qfront = (Q->Qfront + 1) % Q->Qcap;                              //metaferoume to epomeno ws front
    Q->Qsize = Q->Qsize - 1;                                            //meiwnoume to megethos ths
    printf("To stoixeio vghke apo thn Oura.\t");
}

int front_Array(struct Queue_Array *Q){                                 //epistrefei to mprostino stoixeio ths ouras
    if (isEmpty_Array(Q))                                               //an einai adeia epistrefei to mikrotero int
        return INT_MIN;
    return Q->Pin[Q->Qfront];                                           //alliws epistrefei to mprostino
}

int rear_Array(struct Queue_Array *Q){                                  //epistrefei to teleutaio stoixeio ths ouras
    if (isEmpty_Array(Q))                                               //an einai adeio apistrefei ton mikrotero int
        return INT_MIN;
    return Q->Pin[Q->Qrear];                                            //alliws epistrefei to teleutaio stoixeio
}

/*********************************************
 *          ESTW INT OYRA - LISTES           *
 *********************************************/

struct Queue_Lista{                                                     //domh ouras listas
    int elem;                                                           //to stoixeio pou periexei
    struct Queue_Lista *next;                                           //o komvos pou deixnei ston epomeno
};

struct Queue{                                                           //domh queue h opoia krataei ta vasika stoixeia ths listas
    struct Queue_Lista *Qfront, *Qrear;                                 //to front kai to rear, kathws me th lista tha xanontan
};

struct Queue_Lista *newNode(int elem){                                  //dhmiourgia neou komvou
    struct Queue_Lista *temp = NULL;                                    //dhmiourgeia stoixeiou
    temp = (struct Queue_Lista *) malloc(sizeof(struct Queue_Lista));   //desmeush mnhmhs
    temp->elem = elem;                                                  //bazoume to stoixeio sthn lista
    temp->next = NULL;                                                  //thetoume to epomeno ws NULL giati den exei allo mporsta tou
    return temp;
}

struct Queue *createQueue(){                                            //dhmiourgeia ouras
    struct Queue *Q = (struct Queue *) malloc(sizeof(struct Queue));    //desmeush mnhmhs gia thn oura
    Q->Qfront = Q->Qrear = NULL;                                        //thetw ws NULL front kai rear afou den exei dedomena
    return Q;
}

void Enqueue_Lista(struct Queue *Q, int elem){                          //prosthetei dedomeno sthn oura
    struct Queue_Lista *temp = newNode(elem);                           //dhmiourgeia komvou me to elem
    if (Q->Qrear == NULL){                                              //an einai adeia tote to stoixeio
        Q->Qfront = Q->Qrear = temp;                                    //einai front kai rear mazi
        return;
    }
    Q->Qrear->next = temp;                                              //prosthetoume ton neo komvo sto telos ths ouras
    Q->Qrear = temp;                                                    //kai allazoume to rear
    printf("To stoixeio mphke sthn Oura.\t");
}

void Dequeue_Lista(struct Queue *Q){                                    //afairei to prwto stoixeio ths ouras
    if (Q->Qfront == NULL)                                              //an einai adeia epistrefei NULL
        return;
    struct Queue_Lista *temp = Q->Qfront;                               //apothikeuei to front kai
    Q->Qfront = Q->Qfront->next;                                        //to paei ena komvo mprosta
    if (Q->Qfront == NULL)                                              //to to front einai NULL
        Q->Qrear = NULL;                                                //tote kanei kai to rear NULL
    free(temp);                                                         //eleutherwnei mnhmh
    printf("To stoixeio vghke apo thn Oura.\t");
}