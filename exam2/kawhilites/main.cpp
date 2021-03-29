#include <iostream>
#include "heap.h"
using namespace std;
int main () {

    HEAP* heap = NULL;
    heap = Init(16);
    read(heap, "numbers.txt");
    Union(12,8, heap);
    printHeap(heap);
    return 0;
}

