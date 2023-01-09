/******************
 * ESTW LISTA INT *
 ******************/
#include "List.h"

int main(){
    struct Lista *head = (struct Lista *) malloc(sizeof(struct Lista));                     //arxikopoiw pointer typou struct kai megethos struct
    struct Lista *scnd = (struct Lista *) malloc(sizeof(struct Lista));
    struct Lista *thrd = (struct Lista *) malloc(sizeof(struct Lista));
    head->elem = 1, head->next = scnd;                                                      //vazw timh sthn prwth thesh kai thetw to epomeno vhma ths lista mou
    scnd->elem = 2, scnd->next = thrd;
    thrd->elem = 3, thrd->next = NULL;                                                      //next = NULL shmainei oti den exei allo stoixeio h lista mas
    printf("Mhkos listas: %d\t", LLength(head));                                            //emfanizw to mhkos ths listas mou
    printf("Mhkos listas (r): %d\t", LLengthRecur(head));                                   //me anadromh
    LPrint(head);                                                                           //emfanizw th lista
    LPush(&head, 4);                                                                        //vazw to 4 sthn arxh
    LInstert(&head, -1);                                                                    //vazw to -1 sto telos
    LInstertAfter(scnd, 0);                                                                 //vazw to 0 meta to 2
    printf("Mhkos listas: %d\tMhkos listas (r): %d\t", LLength(head), LLengthRecur(head));
    LPrint(head);
    LSearch(head, 3) ? puts("To 3 vrethike!!") : puts("To 3 den vrethike!!");               //anazhthsh tou 3 sthn lista
    LSearchRecur(head, 3) ? puts("To 3 vrethike(r)!!") : puts("To 3 den vrethike(r)!!");    //me anadromh
    printf("To 0 emfanizetai %d fores sth lista\n", LFreq(head, 0));                        //epistrefei poses fores emfanizetai to 0 sth lista
    printf("To 4o stoixeio ths listas: %d\n", LGet(head, 4-1));                             //epistrefei to stoixeio sth thesh pou zhtaw
                                                                                            //kanw to '-1' kathws o xrhsths den kserei oti ksekiname na
                                                                                            //metrame apo to 0
  //printf("To 9o stoixeio ths listas: %d\n", LGet(head, 9));                               //epistrefei diagnostics kai termatizei to programma kalo gia eisodous apo xrhsth

    printf("H Lista taksinomhmenh:\t\t\t"), LQuickSort(&head), LPrint(head);                //quicksort taksinomhsh listas
    printf("H Lista reversed:\t\t\t"), LReverse(&head), LPrint(head);                       //emfanizei ta stoixeia ths listas antistrofa
    LDeleteElem(&head, 3);                                                                  //diagrafw to 3 apo th lista
    printf("Mhkos listas: %d\tMhkos listas (r): %d\t", LLength(head), LLengthRecur(head));
    LPrint(head);
    LSearch(head, 3) ? puts("To 3 vrethike!!") : puts("To 3 den vrethike!!");
    LSearchRecur(head, 3) ? puts("To 3 vrethike(r)!!") : puts("To 3 den vrethike(r)!!");
    LDeletePos(&head, 2);                                                                   //diagrafw th deuterh thesh ths listas
    printf("Mhkos listas: %d\tMhkos listas (r): %d\t", LLength(head), LLengthRecur(head));
    LPrint(head);
    LDeleteAll(&head);                                                                      //diagrafh olhs ths listas
    printf("Mhkos listas: %d\tMhkos listas (r): %d\t", LLength(head), LLengthRecur(head));
    LPrint(head);

    return 0;
}