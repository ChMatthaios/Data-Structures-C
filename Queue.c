#include "Queue.h"

int main(){
    puts("----------------------\nOYRA ME XRHSH PINAKWN.\n----------------------");
    struct Queue_Array *Q = QCreate_Array(10);                                                      //dhmiourgeia ouras
    (isEmpty_Array(Q) == 0) ? puts("Den einai adeia.") : puts("Einai adeia.");                      //epistrefei 0 otan exei stoixeia
    (isFull_Array(Q) == 0) ? puts("Den einai gemath.") : puts("Einai gemath.");                     //epistrefei 0 otan den exei gemisei
    Enqueue_Array(Q, 1),    printf("front = %d | rear = %d\n", front_Array(Q), rear_Array(Q));      //vazei to 1 sthn oura kai epistrefei front kai rear
    Enqueue_Array(Q, 2),    printf("front = %d | rear = %d\n", front_Array(Q), rear_Array(Q));      //vazei to 2 sthn oura kai epistrefei front kai rear
    Dequeue_Array(Q),       printf("front = %d | rear = %d\n", front_Array(Q), rear_Array(Q));      //vgazei to prwto apo thn oura kai epistrefei front kai rear
    Enqueue_Array(Q, 3),    printf("front = %d | rear = %d\n", front_Array(Q), rear_Array(Q));      //vazei to 3 sthn oura kai epistrefei front kai rear
    Enqueue_Array(Q, 4),    printf("front = %d | rear = %d\n", front_Array(Q), rear_Array(Q));      //vazei to 4 sthn oura kai epistrefei front kai rear
    Dequeue_Array(Q),       printf("front = %d | rear = %d\n", front_Array(Q), rear_Array(Q));      //vgazei to prwto apo thn oura kai epistrefei front kai rear
    (isEmpty_Array(Q) == 0) ? puts("Den einai adeia.") : puts("Einai adeia.");
    (isFull_Array(Q) == 0) ? puts("Den einai gemath.") : puts("Einai gemath.");
    puts("\n---------------------\nOYRA ME XRHSH LISTWN.\n---------------------");
    struct Queue *QL = createQueue();
    Enqueue_Lista(QL, 1),   printf("front = %d | rear = %d\n", QL->Qfront->elem, QL->Qrear->elem);  //vazei to 1 sthn oura kai epistrefei front kai rear
    Enqueue_Lista(QL, 2),   printf("front = %d | rear = %d\n", QL->Qfront->elem, QL->Qrear->elem);  //vazei to 2 sthn oura kai epistrefei front kai rear
    Dequeue_Lista(QL),      printf("front = %d | rear = %d\n", QL->Qfront->elem, QL->Qrear->elem);  //vgazei to prwto apo thn oura kai epistrefei front kai rear
    Enqueue_Lista(QL, 3),   printf("front = %d | rear = %d\n", QL->Qfront->elem, QL->Qrear->elem);  //vazei to 3 sthn oura kai epistrefei front kai rear
    Enqueue_Lista(QL, 4),   printf("front = %d | rear = %d\n", QL->Qfront->elem, QL->Qrear->elem);  //vazei to 4 sthn oura kai epistrefei front kai rear
    Dequeue_Lista(QL),      printf("front = %d | rear = %d\n", QL->Qfront->elem, QL->Qrear->elem);  //vgazei to prwto apo thn oura kai epistrefei front kai rear
    return 0;
}