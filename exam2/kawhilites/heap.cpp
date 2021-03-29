#include "heap.h"
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

HEAP* Init(int n){
        // increment
	HEAP* h = new HEAP(n); // using heap constructor to create a heap of capacity n. Passes n as size and is used to dynamically allocate memory for the array
	return h;
}
void printHeap(HEAP* h) {
	cout << "capacity=" << h->capacity << ", size=" << h->size << endl; // printing out capacity and current size
	if (h->size > 0){ // cannot print array of 0, will cause error
	for (int count = 1; count < h->size; count++){ // starting at 1 since index 0 is unused
		cout << "A[" << count << "]=" << h->elements[count]->key << ", "; // printing keys
	}
	cout << "A[" << h->size << "]=" << h->elements[h->size]->key << endl; // printing final key
	}
}

void Insert(HEAP* h, int k) { // used to add to the heap
	h->size++; // current size incremented
	if (h->size > h->capacity) {
		cout << "Over capacity" << endl;
		h->size--;
		return;
	}
	else {
		ElementT element = new ELEMENT(k); // pointer to new ELEMENT struct with key value k
		h->elements[h->size] = element;
	}
}
int findSet(int x, HEAP* h){
	if (h->elements[x]->key <= 0){
		return x;
	}
	else{
		h->elements[x]->key = findSet(h->elements[x]->key, h);
		return h->elements[x]->key;
	}
}
void link(int x, int y, HEAP* h){
	if (-h->elements[x]->key > -h->elements[y]->key){
		h->elements[y]->key = x;
	}
	else{
		if (-h->elements[x]->key == -h->elements[y]->key){
			h->elements[y]->key = h->elements[y]->key - 1;

		}
		h->elements[x]->key = y;
	}
}
void Union(int x, int y, HEAP* h){
	link(findSet(x, h),findSet(y, h), h);
}
void read(HEAP* h, string filename){
        ifstream readfile;
        int a; // number of elements to be added
        int c; // current element to be added
        readfile.open(filename); // opening file
        if (readfile.fail()){ // check if file can be opened
                cout << "Error: cannot open file for reading" << endl;
                return;
        }
        readfile >> a;
        if ( h == nullptr || (h->size + a) > h->capacity || a<= 0) {
                cout << "Error: heap overflow" << endl;
                readfile.close();
                return;
        }
	for (int count = 0; count < a ; count++){ // adding elements from file
                readfile >> c; // reading
                Insert(h, c); // adding to array
	}
        readfile.close(); // closing file
}
