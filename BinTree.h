/**
 * Ena dentro tou opoiou ta "paidia" einai mono duo onomazetai
 * dyadiko dentro, onomazontai aristero kai deksi paidi.
 * Se antithesh me pinakes, listes, stoives kai oures pou einai
 * grammikes domes dedomenwn ta dentra einai ierarxikes domes.
 *
 * Apoteleitai apo ton root pou einai pou einai o koryfaios komvos
 * kai oti vrisketai akrivws apo katw tou onomazetai paidi.
 * Opws fainetai parakatw:
 *          dentro
 *          ------
 *            j    <-- riza / root
 *          /   \
 *         f     k
 *        / \     \
 *       a   h     z    <-- fylla / leaves
 */

#include <stdio.h>                                                                  //vasikh vivliothiki
#include <stdlib.h>                                                                 //malloc kai dynamikh diaxeirish

/*********************************************
 *            ESTW INTEGER DENTRO            *
 *********************************************/

struct BTAr{                                                                        //domh dyadikou dentrou
    int elem;                                                                       //me stoixeio
    struct BTAr *left, *right;                                                      //kai aristero kai deksi paidi
};

struct BTAr *BTACreate(int elem){                                                   //dhmiourgei ton node tou fyllou
    struct BTAr* node = (struct BTAr*)malloc(sizeof(struct BTAr));                  //dhmiourgeia kai desmeush mnhmhs
    node->elem = elem;                                                              //pairnei to stoixeio
    node->left = node->right = NULL;                                                //thetei to aristero kai deksi paidi tou ws NULL kathws den exoun kati allo
    return node;                                                                    //epistrefei ton komvo
}

/********************* DIADIKASIA EISAGWGHS *****************************
 * -> Ksekonwntas ap oth riza (root) tou dentrou anazhtoume ton         *
 *    komvo pou mporei na dextei auto pou theloume na eisagoume.        *
 * -> An vrethei o komvos me auto to stoixeio tote eisagetai            *
 *    kanonika sto dentro.                                              *
 * -> An den vrethei tote mpainei se ena NULL fyllo tou kladou.         *
 ************************************************************************
 * -> Giati omws den mporei na mpei?                                    *
 * -> Auto ginetai kathws an koitaksoume ena dentro apo aristera pros   *
 *    ta deksia tha prepei na phgainei apo to mikrotero sto megalytero, *
 *    dhladh to mikrotero stoixeio tha einai sto teleutaio fyllo sta    *
 *    kai to megalytero sto teleutaio fyllo sta deksia.                 *
 ************************************************************************/

struct BTAr *BTAInsert(struct BTAr *tree, int elem){                                //prosthetei ena stoixeio sto dentro
    if (tree == NULL)       return BTACreate(elem);                                 //an den yparxei komvos ton dhmiourgei kalwntas thn parapanw synarthsh
    if (elem < tree->elem)  tree->left = BTAInsert(tree->left, elem);               //an einai mikrotero tou stoixeiou pou yparxei hdh, tote ksanakalei ton eauto ths me to aristero fyllo tou kladou
    else                    tree->right = BTAInsert(tree->right, elem);             //alliws kalei ton eauto ths me to deksi fyllo tou kladou
    return tree;
}

/********************** DIADIKASIA ANAZHTHSHS ***************************
 * -> Ksekina apo th riza tou dentrou                                   *
 * -> An to stoixeio einai iso me th riza(root) h diadikasia teleiwnei  *
 * -> An to stoixeio einai mikrotero ths rizas tote h diadikasia        *
 *    synexizetai sto aristero ypodentro                                *
 * -> An einai megalytero h diadikasia synexizetai sto deksi ypodentro  *
 * -> An h anazhthsh katalhksei se NULL tote den yparxei to stoixeio    *
 ************************************************************************/

void BTASearch(struct BTAr *tree, int el){                                          //anazhtaei to stoixeio mesa sto dentro
    if (tree == NULL)           printf("Den vrethike to %d.\n", el);                //an einai keno stamataei th diadikasia
    else if (tree->elem == el)  printf("Vrethike to %d.\n", el);                    //otan vrethei to stoxeio emfanizei mhnyma epityxeias
    else if (tree->elem > el)   BTASearch(tree->left, el);                          //an einai megalytero tou stoixeiou pou prospellaunoume tote kalei to aristero ypodentro
    else                        BTASearch(tree->right, el);                         //alliws kalei to deksi ypodentro
}

/*************** DIADIKASIA DIASXISHS ***************
 * -> (A) Prodiatetagmenh diasxish (PreOrder)       *
 *      -> Ksekinaei apo th riza                    *
 *      -> Synexizei sto aristero ypodentro         *
 *      -> Kai termatizei meta to deksi ypodentro   *
 * -> (B) Endodiatetagmenh diasxish (InOrder)       *
 *      -> Ksekinaei apo to aristero ypodentro      *
 *      -> Synexizei me th riza                     *
 *      -> Kai termatizei meta to deksi ypodentro   *
 *          **SAN TAKSINOMHMENH SE AYKSOUSA         *
 * -> (C) Metadiatetagmenh diasxish (PostOrder)     *
 *      -> Ksekinaei apo to aristero ypodentro      *
 *      -> Synexizei me to deksi ypodentro          *
 *      -> kai termatizei meta th riza              *
 ****************************************************/

void BTAPreOrder(struct BTAr *tree){                                                //emfanizei prodiatetamena
    if (tree == NULL)   return;                                                     //an einai kenos termatizei
    printf("%5d", tree->elem), BTAPreOrder(tree->left), BTAPreOrder(tree->right);   //emfanizei opws prepei vasei preorder
}

void BTAInOrder(struct BTAr *tree){                                                 //emfanizei endodiatetamena
    if (tree == NULL)   return;                                                     //an einai keno termatizei
    BTAInOrder(tree->left), printf("%5d", tree->elem), BTAInOrder(tree->right);     //emfanizei opws prepei vasei inorder
}

void BTAPostOrder(struct BTAr *tree){                                               //emfanizei metadiatetamena
    if (tree == NULL)   return;                                                     //an einai keno stamataei
    BTAPostOrder(tree->left), BTAPostOrder(tree->right), printf("%5d", tree->elem); //emfanizei opws prepei vasei postorder
}

/*********************** DIADIKASIA DIAGRAFHS ***********************
 * -> Entopizoume ton komvo kai antimetopizoume to provlhma analoga *
 *    me thn periptwsh.                                             *
 *      -> (A) O komvos pou tha diagrafei einai fyllo               *
 *          -> Tote apla kanoume to aristero h to deksi paidi tou   *
 *             prohgoumenou komvou NULL                             *
 *      -> (B) O komvos pou tha diagrafei exei ena paidi            *
 *          -> An o pateras exei ena paidi ki auto exei allo ena me *
 *             th seira tou tote diagrafetai kanonika kai to eggoni *
 *             ginetai paidi                                        *
 *      -> (C) O komvos pou tha diagrafei exei duo paidia           *
 *          -> An kanena apo ta paidia tou den einai NULL tote o    *
 *             prohgoumenos tou(amesws mikroteros) afhnei th thesh  *
 *             tou kai pairnei th thesh tou komvou pou diagrafetai. *
 ********************************************************************/

struct BTAr *minValue(struct BTAr *tree){                                           //epistrefei th mikroterh timh tou dentrou
    struct BTAr *trexwn = tree;                                                     //dhmiourgei ton trexwn
    while (trexwn && trexwn->left != NULL)                                          //anazhtei sto dentro oso yparxei KAI to aristero fyllo den einai NULL
        trexwn = trexwn->left;                                                      //proxwraei sto dentro aristera gia na brei ton mikrotero
    return trexwn;                                                                  //ton epistrefei
}

struct BTAr *BTADelete(struct BTAr *tree, int e){                                   //diagrafei to element apo to dentro
    if (tree == NULL)   return tree;                                                //an einai adeio termatizei
    if (e < tree->elem)                                                             //an to stoixeio einai mikrotero apo to stoixeio tou dentrou
        tree->left = BTADelete(tree->left, e);                                      //tote sto aristero ypodentro kaleitai o eautos ths me to stoixeio
    else if (e > tree->elem)                                                        //an einai megalytero apo to stoixeio tou dentrou
        tree->right = BTADelete(tree->right, e);                                    //tote sto deksi ypodentro kaleitai o eautos ths me to stoixeio
    else{
        if (tree->left == NULL){                                                    //alliws gia komvous me ena h kanena paidi
            struct BTAr *temp = tree->right;                                        //an to aristero den yparxei krateitai to deksi
            free(tree);                                                             //eleutherwnetai h mnhmh tou
            return temp;                                                            //kai diagrafetai to deksi
        } else if (tree->right == NULL){                                            //kai an einai to deksi NULL
            struct BTAr *temp = tree->left;                                         //krateitai to aristero paidi
            free(tree);                                                             //eleutherwnetai h mnhmh
            return temp;                                                            //kai diagrafetai to aristero
        }
        struct BTAr *temp = minValue(tree->right);                                  //gi autous me duo paidia vriskoume to mikrotero
        tree->elem = temp->elem;                                                    //vazoume to periexomeno ston temp
        tree->right = BTADelete(tree->right, temp->elem);                           //kai diagrafoume ton InOrder diadoxo
    }
    return tree;                                                                    //kai epistrefetai to "kainourio" dentro
}