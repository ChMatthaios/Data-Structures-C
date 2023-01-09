/******************
 * ESTW STACK INT *
 ******************/
#include "Stack.h"

int main(){
    printf("PINAKAS STOIVA!\n");
    int MEG = 10, cnt = 0;
    struct Stoiva_Array S = SCreate_Array(MEG);                                                 //dhmiourgei thn stoiva me xwrhtikothta MEG

    (isFull_Array(&S) != 0) ? puts("Einai gemath.") : puts("Den einai gemath");                 //epistrefei 0 otan einai gemath
    (isEmpty_Array(&S) != 0) ? puts("Einai adeia.") : puts("Den einai adeia");                  //epistrefei 0 otan einai adeia

    push_Array(&S, 1), cnt++,  printf("\tTo teleutaio stoixeio einai: %d\n",peek_Array(&S));    //vazei ena stoixeio sth stoiva kai emfanizei thn koryfh ths stoivas
    push_Array(&S, 2), cnt++,  printf("\tTo teleutaio stoixeio einai: %d\n",peek_Array(&S));    //vazei ena stoixeio sth stoiva kai emfanizei thn koryfh ths stoivas
    pop_Array(&S), cnt--,      printf("\tTo teleutaio stoixeio einai: %d\n",peek_Array(&S));    //vgazei ena stoixeio sth stoiva kai emfanizei thn koryfh ths stoivas
    push_Array(&S, 3), cnt++,  printf("\tTo teleutaio stoixeio einai: %d\n",peek_Array(&S));    //vazei ena stoixeio sth stoiva kai emfanizei thn koryfh ths stoivas
    push_Array(&S, 4), cnt++,  printf("\tTo teleutaio stoixeio einai: %d\n",peek_Array(&S));    //vazei ena stoixeio sth stoiva kai emfanizei thn koryfh ths stoivas
    pop_Array(&S), cnt--,      printf("\tTo teleutaio stoixeio einai: %d\n",peek_Array(&S));    //vgazei ena stoixeio sth stoiva kai emfanizei thn koryfh ths stoivas

    (isFull_Array(&S) != 0) ? puts("Einai gemath.") : puts("Den einai gemath");                 //epistrefei 0 otan einai gemath
    (isEmpty_Array(&S) != 0) ? puts("Einai adeia.") : puts("Den einai adeia");                  //epistrefei 0 otan einai adeia
    printf("[O Pinakas mou: ");
    for (int i = cnt - 1; i >= 0; i--)
        printf("%3d", S.Pin[i]);
    puts("]");

    printf("\nLISTA STOIVA!\n");
    struct Stoiva_Lista *SL = newNode(0);
    (isEmpty_Lista(SL) != 0) ? puts("Einai adeia.") : puts("Den einai adeia");                  //epistrefei 0 otan einai adeia

    push_Lista(&SL, 1), printf("\tTo teleutaio stoixeio einai: %d\n",peek_Lista(SL));           //vazei ena stoixeio sth stoiva kai emfanizei thn koryfh ths stoivas
    push_Lista(&SL, 2), printf("\tTo teleutaio stoixeio einai: %d\n",peek_Lista(SL));           //vazei ena stoixeio sth stoiva kai emfanizei thn koryfh ths stoivas
    pop_Lista(&SL),     printf("\tTo teleutaio stoixeio einai: %d\n",peek_Lista(SL));           //vgazei ena stoixeio sth stoiva kai emfanizei thn koryfh ths stoivas
    push_Lista(&SL, 3), printf("\tTo teleutaio stoixeio einai: %d\n",peek_Lista(SL));           //vazei ena stoixeio sth stoiva kai emfanizei thn koryfh ths stoivas
    push_Lista(&SL, 4), printf("\tTo teleutaio stoixeio einai: %d\n",peek_Lista(SL));           //vazei ena stoixeio sth stoiva kai emfanizei thn koryfh ths stoivas
    push_Lista(&SL, 5), printf("\tTo teleutaio stoixeio einai: %d\n",peek_Lista(SL));           //vazei ena stoixeio sth stoiva kai emfanizei thn koryfh ths stoivas
    pop_Lista(&SL),     printf("\tTo teleutaio stoixeio einai: %d\n",peek_Lista(SL));           //vgazei ena stoixeio sth stoiva kai emfanizei thn koryfh ths stoivas

    (isEmpty_Lista(SL) != 0) ? puts("Einai adeia.") : puts("Den einai adeia");                  //epistrefei 0 otan einai adeia

    Print_Lista(SL);

    return 0;
}