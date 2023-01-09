/************************************************************
 * H Lista einai mia domh h opoia periexei to stoixeio pou  *
 * apothikeuei h kathe komvos kai o diekths gia ton epomeno *
 ************************************************************
 *                  ESTW LISTA TYPOU INTEGER                *
 ************************************************************/
#include <stdio.h>                                          //vasikh vivliothiki
#include <stdlib.h>                                         //malloc kai dynamikh diaxeirish
#include <malloc.h>                                         //calloc, realloc
#include <stdbool.h>                                        //vivliothiki gia boolean
#include <assert.h>                                         //diagnostics

struct Lista{
    int elem;                                               //to stoixeio pou apothikeuoume
    struct Lista *next;                                     //o deikths gia to epomeno
};

void LPush(struct Lista **head, int newElem){               //gia na prosthesei stoixeio sthn arxh ths listas kai to
                                                            //head einai to head ths listas pou theloume na allaksoume
    struct Lista *new_node = (struct Lista *) malloc(sizeof(struct Lista));
    new_node->elem = newElem;                               //bazw to element
    new_node->next = *head;                                 //to kanw na deixnei sto prohgoumeno head ths listas
    *head = new_node;                                       //kanw head to new_node
}

void LInstert(struct Lista **head, int newElem){            //gia na prosthetei ena stoixeio sto telos ths listas
    struct Lista *new_node = (struct Lista*) malloc(sizeof(struct Lista));
    struct Lista *last = *head;
    new_node->elem = newElem;                               //bazw to element
    new_node->next = NULL;                                  //kanw to next tou na deixnei se NULL
    if (*head == NULL){                                     //an einai kenh kane to stoixeio ws head ths
        *head = new_node;
        return;
    }
    while (last->next != NULL)                              //alliws proxwraw mexri na vrw to teleutaio
        last = last->next;
    last->next = new_node;                                  //allazw to next tou prwhn teleutaiou na deixnei sto neo
}

void LInstertAfter(struct Lista *p_nd, int newElem){        //vazei to stoixeio meta apo sygkekrimenh thesh
    if (p_nd == NULL){
        puts("O prohgoumenos den mporei na einai NULL.");
        return;                                             //check an yparxei o prhgoumenos node kai epistrofh lathous
    }
    struct Lista *new_node = (struct Lista *) malloc(sizeof(struct Lista));
    new_node->elem = newElem;                               //bazw to stoixeio
    new_node->next = p_nd->next;                            //thetw ws next auto pou eixe prohgoumenws
    p_nd->next = new_node;                                  //thetw to next tou prohgoumenou ws to kainourio node
}

int LLength(struct Lista *head){                            //epistrefei to megethos ths listas
    int metrhths = 0;                                       //metrhths thesewn
    struct Lista *trexwn = head;                            //vazw ws trexwn too head ths listas
    while (trexwn != NULL)                                  //oso synexizei h lista
        metrhths++, trexwn = trexwn->next;                  //auksanw metrhth kai paw sthn epomenh thesh ths listas
    return metrhths;
}

int LLengthRecur(struct Lista *head){                       //h idia me thn LLength alla me recursion
    if (head == NULL) return 0;                             //an den exei stoixeia epistrefei 0
    else              return 1 + LLengthRecur(head->next);  //alliws kalei ton eauto ths oso vriskei epomena nodes na paei
}

void LDeleteElem(struct Lista **head, int e){               //diagrafei ton komvo pou periexei to stoixeio pou thelw na diagrapsw
    struct Lista *tmp = *head, *prev;                       //krataw to head node
    if (tmp != NULL && tmp->elem == e){                     //an to head den einai null kai periexei to stoixeio pou thelw na diagrapsw
        *head = tmp->next;                                  //allazw to head
        free(tmp);                                          //eleutherwnw to palio head
        return;
    }
    while (tmp != NULL && tmp->elem != e){                  //psaxnw to stoixeio sth lista
        prev = tmp;                                         //gia na kinithw allazw thn timh tou prev me thn epomenh gia na "kinoumai" sth lista
        tmp = tmp->next;                                    //kai proxwraw sto epomeno
    }
    if (tmp == NULL)                                        //to stoixeio den vrethike
        return;
    prev->next = tmp->next;                                 //vgazw to stoixeio apo th lista
    free(tmp);                                              //eleutherwnw mnhmh
}

void LDeletePos(struct Lista **head, int p){                //diagrafei mia thesh ths listas
    if (head == NULL)                                       //an einai kenh h lista
        return;
    struct Lista *tmp = *head;                              //apothikeuw to head
    if (p == 0){                                            //an prepei na diagrafei to head
        *head = tmp->next;                                  //allazw to head
        free(tmp);                                          //eleutherwnw mnhmh
        return;
    }
    for (int i = 0; tmp!= NULL && i < p-1; i++)             //psaxnw sth lista
        tmp = tmp->next;                                    //kinoumai allazwntas to next
    if (tmp == NULL || tmp->next == NULL)                   //an exei dwsei megalyterh thesh apo th lista
        return;
    struct Lista *nxt = tmp->next->next;                    //to tmp->next einai auto pou thelw na diagrapsw
                                                            //ara krataw to node apo to epomeno apo auto pou thelw na diagrapsw
                                                            //gia na mh xathei h seira
    free(tmp->next);                                        //diagrafw to tmp->next
    tmp->next = nxt;                                        //vgazw to diegrammeno node apo th lista
}

void LDeleteAll(struct Lista **head){                       //diagrafei olh th lista
    struct Lista *trexwn = *head, *epomenos;                //krataw tis theseis pou vriskomai
    while (trexwn != NULL){                                 //mexri na teleiwsei h lista
        epomenos = trexwn->next;                            //proxwraw stis theseis
        free(trexwn);                                       //katharizw ton trexwn
        trexwn = epomenos;                                  //epomenh thesh
    }
    *head = NULL;                                           //mhdenizw to head
}

bool LSearch(struct Lista *head, int a){                    //anazhthsh sthn lista tou stoixeiou a
    struct Lista *trexwn = head;                            //arxikopoiw to trexwn
    while (trexwn != NULL){
        if (trexwn->elem == a) return true;                 //an to vrei epistrefei alithes
        trexwn = trexwn->next;                              //an oxi paei sto epomeno
    }
    return false;                                           //an den to vrei epistrefei pseudes
}

bool LSearchRecur(struct Lista *head, int a){               //h idia me thn LSearch alla me recursion
    if (head == NULL)    return false;                      //an einai kenh epistrefei pseudes
    if (head->elem == a) return true;                       //an to head exei auto pou psaxnoume epistrefei alithes
    return LSearchRecur(head->next, a);                     //ksanakalei ton eauto ths me ton epomeno node ths listas
}

int LGet(struct Lista *head, int N){                        //epistrefei to N-osto stoixeio ths listas
    struct Lista *trexwn = head;                            //o trexwn node pou eimaste
    int metrhths = 0;                                       //metrhths gia th thesh pou eimaste
    while (trexwn != NULL){                                 //oso yparxoun nodes
        if (metrhths == N) return trexwn->elem;             //an o metrhths ftasei ton arithmo pou edwsa
        metrhths++;                                         //an oxi tote auksanw ton metrhth
        trexwn = trexwn->next;                              //proxwraw sth lista
    }
    assert(0);                                              //an ftasei ws edw o xrhsths zhtaei gia kati pou den yparxei opote epistrefw lathos
}

int LFreq(struct Lista *head, int f){                       //metraei poses fores emfanizetai to f sthn lista
    struct Lista *trexwn = head;
    int freq = 0;                                           //metrhths gia frequency stoixeiou
    while (trexwn != NULL){                                 //proxwraw sth lista
        if (trexwn->elem == f)                              //an to vrei
            freq++;                                         //auksanei ton metrhth
        trexwn = trexwn->next;                              //kai paei sto epomeno
    }
    return freq;                                            //epistrefei ton metrhth
}

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! QUICKSORT SE LISTA !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! - https://www.geeksforgeeks.org/quicksort-on-singly-linked-list/
struct Lista* getTail(struct Lista* cur){                   //epistrefei ton teleutaio komvo ths listas
    while (cur != NULL && cur->next != NULL)
        cur = cur->next;
    return cur;
}

struct Lista* partition(struct Lista* head,                 //Spaei thn lista kratwntas ws pivot to teleutaio stoixeio
                        struct Lista* end,
                        struct Lista** newHead,
                        struct Lista** newEnd){
    struct Lista* pivot = end;                              //to pivot einai metro sygkrishs gia th lista, opou an einai megalytero
    struct Lista *prev = NULL, *cur = head, *tail = pivot;  //paei meta to tail kai an einai mikrottero menei ekei pou einai
    while (cur != pivot) {                                  //Kata to xwrisma ths listas kai to head kai to tail ths listas mporei na exoun allaksei opote ta ananewnoume me to newHead kai newEnd
        if (cur->elem < pivot->elem) {                      //o prwtos komvos pou tha exei timh mikroterh tou pivot tha gine ito neo head
            if ((*newHead) == NULL)
                (*newHead) = cur;
            prev = cur;                                     //to prohgoumeno ginetai trexwn kai
            cur = cur->next;                                //synexizw sth lista mou
        } else{                                             //an o komvos einai megalyteros tou pivot
            if (prev)                                       //metaferei to epomeno tou teleutaiou sto trexwn kai allazei to tail
                prev->next = cur->next;
            struct Lista* tmp = cur->next;                  //kratame to epomeno
            cur->next = NULL;                               //to trexwn to kanoume to kainourio tail
            tail->next = cur;                               //kai antallasoume next
            tail = cur;                                     //tail ginetai to trexwn
            cur = tmp;                                      //antallasoume ta trexwn kai to epomeno
        }
    }
    if ((*newHead) == NULL)                                 //an to pivot einai to mikrotero sth lista tote ginetai head
        (*newHead) = pivot;
    (*newEnd) = tail;                                       //enhmerwnoume to neo tail
    return pivot;                                           //epistrefei to pivot
}

struct Lista* LQuickSortRecur(struct Lista* head,           //edw ginetai h taksinomhsh ektos tou teleutaiou
                              struct Lista* end){
    if (!head || head == end)                               //an exei mono head h lista
        return head;
    struct Lista *newHead = NULL, *newEnd = NULL;           //dhmiourgoume nea head kai end gia na mporoume na kratame ta dedomena gia allages
    struct Lista* pivot                                     //to partition tha spaei ton pinaka kai tha enhmerwnei to pivot kai newHead kai newEnd
        = partition(head, end, &newHead, &newEnd);
    if (newHead != pivot) {                                 //an to pivot einai to mikrotero den xreiazetai na kanw anadromh sto aristero meros
        struct Lista* tmp = newHead;                        //kanw to node prin apo to pivot na exei timh NULL
        while (tmp->next != pivot)                          //psaxnw to pivot
            tmp = tmp->next;                                //proxwraw sth lista
        tmp->next = NULL;                                   //thetw NULL
        newHead = LQuickSortRecur(newHead, tmp);            //anadromh gia th lista prin to pivot
        tmp = getTail(newHead);                             //allazw to epomeno tou teleutaiou kombou aristera tou pivot
        tmp->next = pivot;
    }
    pivot->next = LQuickSortRecur(pivot->next, newEnd);     //anadromh gia th lista deksia tou pivot
    return newHead;
}

void LQuickSort(struct Lista** head){                       //h basikh synarthsh quicksort h opoia kalei th synarthsh anadromhs
    (*head) = LQuickSortRecur(*head, getTail(*head));
    return;
}
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!TELOS QUICKORT SE LISTA !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! - https://www.geeksforgeeks.org/quicksort-on-singly-linked-list/

void LReverse(struct Lista **head){                         //antistrefei ta stoixeia ths listas
    struct Lista *prohgoumenos = NULL, *epomenos = NULL;    //arxikopoihsh nohtwn nodes
    struct Lista *trexwn = *head;                           //trexwn node
    while (trexwn !=NULL)                                   //swap twn nodes gyrw apo ton trexwn
        epomenos = trexwn->next,
        trexwn->next = prohgoumenos,
        prohgoumenos = trexwn,
        trexwn = epomenos;
    *head = prohgoumenos;
}

void LPrint(struct Lista *l){                               //emfanish listas
    printf("[H Lista mou:");
    while(l != NULL)                                        //oso yparxoun stoixeia
        printf("%3d", l->elem),                             //emfanizei to element pou einai sth seira
        l = l->next;                                        //kai kalei ton deikth gia to epomeno wste na allaksei timh
    puts("]");
}