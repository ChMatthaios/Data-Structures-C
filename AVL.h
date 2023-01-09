/**
 * AVL dentra einai ena isorropismeno dyadiko dentro opou h diafora metaksy
 * deksiou kai aristerou ypodentrou den mporei na einai panw apo 1.
 * px:
 * 		   12
 * 		 /    \
 * 		8     18
 *             / \    /
 *            5  11  17
 *           /
 *          4
 */
#include <stdio.h>
#include <stdlib.h>

/***************************************************
 *              ESTW INTEGER AVL-TREE              *
 ***************************************************/

struct AVL{                                                                     //domh pou ftiaxnei to dentro
	int elem, ypsos;                                                        //apothikeuei to stoixeio kai to ypsos
	struct AVL *left, *right;                                               //kathws kai to aristero kai deksi paidi
};

int AVL_max(int x, int y){return (x > y) ? x : y;}                              //synarthsh pou epistrefei to max metaksy duo akeraiwn

int AVL_ypsos(struct AVL *A){                                                   //synarthsh pou epistrefei to ypsos tou dentrou
	if (A == NULL)	return 0;                                               //an einai adeio epistrefei 0
	return A->ypsos;                                                        //alliws to dothen ypsos
}

struct AVL *AVL_new(int elem){                                                  //synarthsh pou dhmiourgei neo fyllo
	struct AVL *newNode = (struct AVL *) malloc(sizeof(struct AVL));
	newNode->elem = elem;                                                   //bazei thn timh sto fyllo
	newNode->left = newNode->right = NULL;                                  //thetei aristero kai deksi paidi ws mhden
	newNode->ypsos = 1;                                                     //afou exei dhmiourgithei exei ypsos 1
	return newNode;
}

struct AVL *AVL_deksiaPeristrofh(struct AVL *y){                                //synarthsh h opoia kanei peristrofh dentrou me kentro to y
    struct AVL *root = y->left;                                                 //krataei ws riza to aristero fyllo tou y
    struct AVL *P = root->right;                                                //kanei pivot to deksi
    root->right = y;                                                            //fernei to y sto aristero fyllo tou neou root
    y->left = P;                                                                //aristero fyllo tou y ginetai to prwhn deksi tou y
    y->ypsos = AVL_max(AVL_ypsos(y->left), AVL_ypsos(y->right)) + 1;            //allazoume to sxetiko ypsos tou fyllou y
    root->ypsos = AVL_max(AVL_ypsos(root->left), AVL_ypsos(root->right)) + 1;   //kai tou neou root
    return root;
}

struct AVL *AVL_aristerhPeristrofh(struct AVL *x){                              //synarthsh h opoia kanei peristrofh dentrou me kentro to x
    struct AVL *root = x->right;                                                //krataei ws riza to aristero fyllo tou x
    struct AVL *P = root->left;                                                 //kanei pivot to deksi
    root->left = x;                                                             //fernei to x sto aristero fyllo tou neou root
    x->right = P;                                                               //aristero fyllo tou A ginetai to prwhn deksi tou x
    x->ypsos = AVL_max(AVL_ypsos(x->left), AVL_ypsos(x->right)) + 1;            //allazoume to sxetiko ypsos tou fyllou x
    root->ypsos = AVL_max(AVL_ypsos(root->left), AVL_ypsos(root->right)) + 1;   //kai tou neou root
    return root;
}

int AVL_getIsorropia(struct AVL *A){                                            //epistrefei to factor isorropias tou dentrou
    if (A == NULL)  return 0;                                                   //an einai keno mhden
    return AVL_ypsos(A->left) - AVL_ypsos(A->right);                            //alliws th diafora tous
}

struct AVL *AVL_Insert(struct AVL *A, int elem){                                //synarthsh pou prosthetei fyllo sto dentro
    if (A == NULL)  return AVL_new(elem);                                       //an einai keno dhmiourgei neo komvo
    if (elem < A->elem)         A->left = AVL_Insert(A->left, elem);            //an to stoixeio einai mikrotero tou fyllou tote paei sto aristero ypodentro kathe fora kalwntas ton eauto ths
    else if (elem > A->elem)    A->right = AVL_Insert(A->right, elem);          //an to stoixeio einai megalytero tou fyllou tote paei sto deksi ypodentro kathe fora kalwntas ton eauto ths
    else                        return A;                                       //ta omoia stoixeia den epitrepontai sta AVL dentra
    A->ypsos = 1 + AVL_max(AVL_ypsos(A->left), AVL_ypsos(A->right));            //allazoume to ypsos tou "patera" komvou
    int bal = AVL_getIsorropia(A);                                              //pairnoume to factor isorropias tou patera gia nadoume an to exei xasei kai den einai pleon AVL dentro
                                                                                //opou an o komvos einai ektos isorropias tha ginoun 4 kinhseis
    if (bal > 1 && elem < A->left->elem)    return AVL_deksiaPeristrofh(A);     //periptwsh Aristera - Aristera
    if (bal > 1 && elem > A->right->elem){                                      //periptwsh Aristera - Deksia
        A->left = AVL_aristerhPeristrofh(A->left);                              //opou kanoume aristerh peristrofh sto aristero fyllo
        return AVL_deksiaPeristrofh(A);                                         //kai deksia peristrofh se olo ton komvo
    }
    if (bal < -1 && elem > A->right->elem)  return AVL_aristerhPeristrofh(A);   //periptwsh Deksia - Deksia
    if (bal < -1 && elem < A->right->elem){                                     //periptwsh Deksia - Aristera
        A->right = AVL_deksiaPeristrofh(A->right);                              //pou kanoume deksia peristrofh sto deksi fyllo
        return AVL_aristerhPeristrofh(A);                                       //kai aristerh peristrofh se olo ton komvo
    }
    return A;                                                                   //alliws epistrefoume ton mh allagmeno komvo
}

struct AVL *AVL_minValue(struct AVL *A){                                        //synarthsh pou epistrefei thn elaxisth timh tou dentrou
    struct AVL *cur = A;                                                        //dhmiourgw ton trexwn komvo
    while (cur->left != NULL)                                                   //oso den vriskw NULL sta aristera fylla synexizw
        cur = cur->left;                                                        //proxwraw sta aristera paidia kathws ekei tha einai ta mikrotera stoixeia
    return cur;                                                                 //epistrefw to aristero fyllo pou den exei allo aristero fyllo
}

struct AVL *AVL_Delete(struct AVL *A, int elem){                                //synarthsh h opoia diagrafei stoixeio apo to dentro
    if (A == NULL)  return A;                                                   //an den yparxei epistrefei to dentro
    if (elem < A->elem)         A->left = AVL_Delete(A->left, elem);            //an to stoixeio eina mikrotero apo tou fyllou psaxnei sto aristero ypodentro
    else if (elem > A->elem)   A->right = AVL_Delete(A->right, elem);           //alliws an einai megalytero psaxnei sto deksi ypodentro
    else{
        if ((A->left == NULL) || (A->right == NULL)){                           //alliws an den exei fylla h exei mono ena
            struct AVL *temp = A->left ? A->left : A->right;                    //gemizei mia proswrinh metablhth me opoio fyllo exeie timh
            if (temp == NULL){                                                  //an den exei kanena fyllo timh
                temp = A;                                                       //tha valei sth proswrinh thn riza
                A = NULL;                                                       //kai tha kanei th riza mhden
            }else
                *A = *temp;                                                     //alliws tha kanei to fyllo to proswrino kai
            free(temp);                                                         //tha eleutherwsei th mnhmh ths proswrinhs(digrafh)
        }else{
            struct AVL *temp = AVL_minValue(A->right);                          //alliws an exei parapanw paidia tha kanei pali ena temp
            A->elem = temp->elem;                                               //tha krathsei thn timh tou fyllou ekei
            A->right = AVL_Delete(A->right, temp->elem);                        //kai tha kalesei ton eauto ths gia na synexisei to psaksimo sta fylla (inorder - smallest to the left)
        }
    }
    if (A == NULL)  return A;                                                   //an exei mono ena komvo epestrepse ton komvo
    A->ypsos = 1 + AVL_max(AVL_ypsos(A->left), AVL_ypsos(A->right));            //ananewnoume to ypsos tou komvou pou vriskomaste
    int bal = AVL_getIsorropia(A);                                              //pairnoume to factor isorropias tou komvou
                                                                                //exoume 4 periptwseis
    if (bal > 1 && AVL_getIsorropia(A->left) >= 0)                              //periptwsh Aristera - Aristera
        return AVL_deksiaPeristrofh(A);                                         //kanei deksia peristrofh ston komvo A
    if (bal > 1 && AVL_getIsorropia(A->left) < 0){                              //periptwsh Aristera - Deksia
        A->left = AVL_aristerhPeristrofh(A->left);                              //kanei aristerh peristrofh sto aristero fyllo tou komvou A
        return AVL_deksiaPeristrofh(A);                                         //kai deksia peristrofh ston komvo A
    }
    if (bal < -1 && AVL_getIsorropia(A->right) <= 0)                            //periptwsh Deksia - Deksia
        return AVL_aristerhPeristrofh(A);                                       //kanei aristerh peristrofh ston komvo A
    if (bal < -1 && AVL_getIsorropia(A->right) > 0){                            //periptwsh Deksia - Aristera
        A->left = AVL_deksiaPeristrofh(A->right);                               //kanei deksia peristrofh sto aristero fyllo tou komvou A
        return AVL_aristerhPeristrofh(A);                                       //kai aristerh peristrofh ston komvo A
    }
    return A;
}

/*************** DIADIKASIA DIASXISHS ***************
 * -> (A) Prodiatetagmenh diasxish (PreOrder)       *
 *      -> Ksekinaei apo th riza                    *
 *      -> Synexizei sto aristero ypodentro         *
 *      -> Kai termatizei meta to deksi ypodentro   *
 ****************************************************/

void AVL_PreOrder(struct AVL *A){                                               //emfanizei prodiatetagmena to dentro
    if (A != NULL){                                                             //an yparxei to dentro
        printf("%5d", A->elem);                                                 //emfanizei th riza
        AVL_PreOrder(A->left);                                                  //meta me th seira to aristero ypodentro
        AVL_PreOrder(A->right);                                                 //kai telos me th seira to deksi ypodentro
    }
}