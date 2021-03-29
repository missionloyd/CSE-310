#ifndef HEAP_H
#define HEAP_H
#include <string>
using namespace std;
struct ELEMENT {
    int key;

    ELEMENT(int val){ //constructor
	this->key = val;	   
    }
};

typedef ELEMENT* ElementT; // pointer to ELEMENT

struct HEAP {
    int capacity; // max capacity
    int size; // current size
    int calls; // number of calls to minHeapify
    ElementT* elements; // pointer to pointer of ELEMENT

    HEAP(){ // default constructor
    }
    HEAP(int n){ // constructor
    	this->capacity = n; // max capacity set
	this->size = 0; // empty array
	this->elements = new ElementT[n+1]; // dynamically allocating memory for an array of pointers of size capacity + 1 to ELEMENT data types
    	this->calls = 0; // initialized at 0
    }
};

HEAP* Init(int n); // initalize heap
void BuildHeap(HEAP* h); // builds heap
void printHeap(HEAP* h); // print heap
void Insert(HEAP* h, int k); // Add to heap
int findSet(int x, HEAP* h);
void read(HEAP* h, string filename);
void link(int x, int y, HEAP* h);
void Union(int x, int y, HEAP* h);
#endif

