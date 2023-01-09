#include "Heap.h"

void printHeap(struct MinHeap *M){
	puts("");
	for (int i = 0; i < M->megethos; i++)
        printf("%5d", M->Pin[i]);
}

int main(){
	struct MinHeap *M = MinHeap_Create(11);

	MinHeap_Insert(M, 3);
	MinHeap_Insert(M, 2);
	printHeap(M);

	MinHeap_deleteElem(M, 0);
	printHeap(M);

	MinHeap_Insert(M, 15);
	MinHeap_Insert(M, 5);
	printHeap(M);

	MinHeap_deleteElem(M, 3);
	printHeap(M);

	MinHeap_Insert(M, 4);
	MinHeap_Insert(M, 45);
	printHeap(M);

	return 0;
}