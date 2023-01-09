/*
 * H stoiva einai mia domh h opoia ylopoiei thn leitourgeia LIFO (Last In First Out)
 * Ousiastika san mia stoiva apo piata etsi leitourgei ki auth kai exei tis parakatw
 * vasikes leitourgies:
 *  a)push : vazei ena dedomeno mesa sth stoiva
 *  b)pop  : afairei ena dedomeno apo th stoiva
 *  c)top  : epistrefei to teleutaio stoixeio pou mphke sth stoiva
 *  d)empty: epistrefei an einai adeia h oxi
 *
 * Mporei na ylopoiithei me pinakes kai me listes.
 */
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

/*************************************************
 *           ESTW INT STOIVA - PINAKES           *
 *************************************************/

struct Stoiva_Array{
    int top, xwrhtikothta, *Pin;                                                        //koryfh, xwrhtikothta kai o pinakas stoivas
};

struct Stoiva_Array SCreate_Array(int x){                                               //dhmiourgei thn stoiva me arxikh xwrhtikothta kai megethos 0
    struct Stoiva_Array *Stack = NULL;
    Stack = (struct Stoiva_Array*) malloc(sizeof(struct Stoiva_Array));                 //arxikopoihsh pinaka me megathos Stoivas
    Stack->xwrhtikothta = x;                                                            //thetw megethos, top
    Stack->top = -1;
    Stack->Pin = (int *) malloc(Stack->xwrhtikothta * sizeof(int));                     //arxikopoiw pinaka megethous x
    return *Stack;
}

int isFull_Array(struct Stoiva_Array *S)    {return S->top == S->xwrhtikothta - 1;}     //epistrefei an einai gemath h stoiva
int isEmpty_Array(struct Stoiva_Array *S)   {return S->top == -1;}                      //epistrefei an einai adeia h stoiva

void push_Array(struct Stoiva_Array *S, int elem){                                      //prosthetei ena stoixeio apo th stoiva kai epistrefei top-1
    if (isFull_Array(S))                                                                //elegxei an einai gemath h stoiva
        return;
    S->Pin[++S->top] = elem, printf("Stoixeio prostethike sth stoiva. ");               //sthn epomenh thesh tou pinaka vazei to elem
}

void pop_Array(struct Stoiva_Array *S){                                                 //afairei ena stoixeio apo th stoiva kai epistrefei top-1
    if (isEmpty_Array(S))                                                               //elegxei an einai adeia
        return;
    S->Pin[S->top--], printf("Stoixeio afairethike apo sth stoiva. ");
}

int peek_Array(struct Stoiva_Array *S){                                                 //epistrefei to top stoixieo ths stoivas
    if (isEmpty_Array(S))
        return INT_MIN;
    return S->Pin[S->top];
}

/*************************************************
 *            ESTW INT STOIVA - LISTES           *
 *************************************************/

struct Stoiva_Lista{                                                                    //struct stoivas
    int elem;                                                                           //stoixeio stoivas
    struct Stoiva_Lista *next;                                                          //epomenos kombos stoivas
};

struct Stoiva_Lista *newNode(int elem){                                                 //dhmiourgei kommo gia th stoiva
    struct Stoiva_Lista *stackNode = NULL;                                              //arxikopoihsh kombou
    stackNode = (struct Stoiva_Lista*) malloc(sizeof(struct Stoiva_Lista));
    stackNode->elem = elem;                                                             //vazw o elem mesa sth stoiva
    stackNode->next = NULL;                                                             //thn kanw teleutaio kombo ths stoivas
    return stackNode;
}

int isEmpty_Lista(struct Stoiva_Lista *S){return !S;}                                   //epistrefei an einai adeia h stoiva

void push_Lista(struct Stoiva_Lista **S, int elem){                                     //prosthetei ena stoixeio sth stoiva
    struct Stoiva_Lista *stackNode = newNode(elem);                                     //dhmiourgei neo kombo kai to vazei sto stackNode
    stackNode->next = *S;                                                               //ton topothetei sto epomeno tou prwhn teleutaiou
    *S = stackNode, printf("Stoixeio prostethike sth stoiva.");                         //to vazei sth stoiva
}

void pop_Lista(struct Stoiva_Lista **S){                                                //afairei stoixeia apo th stoiva
    if (isEmpty_Lista(*S))                                                              //elegxei an einai adeia h stoiva
        return;
    struct Stoiva_Lista *temp = *S;
    *S = (*S)->next;                                                                    //dine thn epomenh timh sto S
    int popped = temp->elem;                                                            //to popped krataei to dedomeno pou theloume na diwksoume
    free(temp);                                                                         //eleutherwnoume th mnhmh
    printf("Stoixeio afairethike apo sth stoiva. ");
}

int peek_Lista(struct Stoiva_Lista *S){                                                 //epistrefei to koryfaio dedomeno tou pinaka
    if (isEmpty_Lista(S))                                                               //elegxei an einai adeia
        return INT_MIN;
    return S->elem;                                                                     //LIFO opote apla epistrefei to prwto pou vriskei kathw einai to teleutaio pou mphke
}

void Print_Lista(struct Stoiva_Lista *l){                                               //emfanish listas
    printf("[H Lista mou:");
    while(l != NULL)                                                                    //oso yparxoun stoixeia
        printf("%3d", l->elem),                                                         //emfanizei to element pou einai sth seira
        l = l->next;                                                                    //kai kalei ton deikth gia to epomeno wste na allaksei timh
    puts("]");
}