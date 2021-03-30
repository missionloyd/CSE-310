/* This is a MIN heap program. All you need to do is enter the array and the heap commands in main.
 * This program provides outputs similar to project 2. This program will automatically build the heap and
 * heapify the array you entered similar to project 2 aswell as provide the number of heapify calls when
 * build heap and extract are run. This heap uses indexing at 1 as you can see when the heap is outputted.
*/

// A C++ program to demonstrate common Binary Heap Operations
#include<iostream>
#include<climits>
using namespace std;

// Prototype of a utility function to swap two integers
void swap(int *x, int *y);

// A class for Min Heap
class MinHeap
{
    int *harr; // pointer to array of elements in heap
    int capacity; // maximum possible size of min heap
    int heap_size; // Current number of elements in min heap
public:
    // Constructor
    MinHeap(int capacity, int arr[],int size);

    // to heapify a subtree with the root at given index
    void MinHeapify(int ,int &counter);

    void buildHeap(int arr[],int size);

    int parent(int i) { return (i)/2; }

    // to get index of left child of node at index i
    int left(int i) { return (2*i); }

    // to get index of right child of node at index i
    int right(int i) { return (2*i+1); }

    // to extract the root which is the minimum element
    void extractMin();

    // Decreases key value of key at index i to new_val
    void decreaseKey(int i, int new_val);

    // Inserts a new key 'k'
    void insertKey(int k);

    void printHeap();

};

void MinHeap::buildHeap(int arr[],int size) {

    int counter = 0;
    for(int i=1;i<=size;i++){
        harr[i]=arr[i-1];
        heap_size++;
    }
    for (int iterate = heap_size/2;iterate >= 1;iterate--){
        MinHeapify(iterate,counter);
    }
    cout<<"The number of heapify calls from build heap: "<<counter<<"\n";
}

// Constructor: Builds a heap from a given array a[] of given size
MinHeap::MinHeap(int cap,int arr[],int size)
{
    heap_size = 0;
    capacity = cap;
    harr = new int[cap+1];
    buildHeap(arr,size);
    cout<<"This is the original min heap:\n";
    printHeap();
    cout<<"\nHeap commands:\n";
}

// Inserts a new key 'k'
void MinHeap::insertKey(int k)
{
    cout<<"InsertKey("<<k<<")\n";

    if (heap_size == capacity)
    {
        cout << "\nOverflow: Could not insertKey\n";
        return;
    }

    // First insert the new key at the end
    heap_size++;
    int i = heap_size;

    // Fix the min heap property if it is violated
    while (i > 1 && harr[parent(i)] > k)
    {
        harr[i] = harr[parent(i)];
        i = parent(i);
    }
    harr[i] = k;
    cout<<"After insert:\n";
    printHeap();
}

// Decreases value of key at index 'i' to new_val.  It is assumed that
// new_val is smaller than harr[i].
void MinHeap::decreaseKey(int i, int new_val)
{
    
     if(new_val>harr[i]){
        cout<<"Error: new key is larger than current\n";
        printHeap();
        return;
    }
    cout<<"decreaseKey("<<i<<","<<new_val<<")\n";
    harr[i] = new_val;
    while (i > 1 && harr[parent(i)] > harr[i])
    {
        swap(&harr[i], &harr[parent(i)]);
        i = parent(i);
    }
    cout<<"After decreaseKey:\n";
    printHeap();
}

// Method to remove minimum element (or root) from min heap
void MinHeap::extractMin()
{
    cout<<"extractMin()\n";
    int counter = 0;
    if (heap_size < 1){
        cout<<"Heap is empty \n";
        return;
    }
    // Store the minimum value, and remove it from heap
    int root = harr[1];
    harr[1] = harr[heap_size];
    heap_size--;
    MinHeapify(1,counter);
    cout<<"The number of heapify calls from extractMin: "<<counter<<"\n";
    cout<<"Deleted key: "<<root<<"\n";
    printHeap();
}

void MinHeap::printHeap() {
    std::cout<<"capacity="<<capacity;
    std::cout<<", size="<<heap_size<<"\nIndex:\t\t";
    for(int increment = 1; increment<=heap_size;increment++){
        cout<<increment<<"\t";
    }
    std::cout<<"\nElement:\t";
    for(int increment = 1; increment<=heap_size;increment++){
        cout<<harr[increment]<<"\t";
    }
    std::cout<<"\n\n";
}

// A recursive method to heapify a subtree with the root at given index
// This method assumes that the subtrees are already heapified
void MinHeap::MinHeapify(int i, int &counter)
{
    counter++;
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l <= heap_size && harr[l] < harr[i])
        smallest = l;
    if (r <= heap_size && harr[r] < harr[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(&harr[i], &harr[smallest]);
        MinHeapify(smallest,counter);
    }
}

// A utility function to swap two elements
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Driver program to test above functions
int main()
{
    //************************************************************************
    //Enter array here

    //Examples
    //int arr[] = {70,60,50,40,30,20,10};
    int arr[] = {11,13,15,17,19,21,23,25,27,29};
    
    //************************************************************************
    int size=sizeof(arr)/sizeof(arr[0]);
    MinHeap h(20,arr,size);

    //************************************************************************
    //Enter commands here
    //Format should be: h.[enter function];

    /*Examples
     * h.insertKey(4);
     * h.extractMin();
     * h.decreaseKey(3, 28);
    */
    //************************************************************************

    return 0;
}
