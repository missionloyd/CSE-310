/* This is a MAX heap program. All you need to do is enter the array and the heap commands in main.
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

// A class for Max Heap
class MaxHeap
{
    int *harr; // pointer to array of elements in heap
    int capacity; // maximum possible size of max heap
    int heap_size; // Current number of elements in max heap
public:
    // Constructor
    MaxHeap(int capacity, int arr[], int size);

    // to heapify a subtree with the root at given index
    void MaxHeapify(int ,int &counter);

    void buildHeap(int arr[],int size);

    int parent(int i) { return (i)/2; }

    // to get index of left child of node at index i
    int left(int i) { return (2*i); }

    // to get index of right child of node at index i
    int right(int i) { return (2*i+1); }

    // to extract the root which is the maximum element
    void extractMax();

    // Increases key value of key at index i to new_val
    void increaseKey(int i, int new_val);

    // Returns the maximum key (key at root) from max heap
    int getMax() { return harr[1]; }

    // Inserts a new key 'k'
    void insertKey(int k);

    void printHeap();

};

void MaxHeap::buildHeap(int arr[], int size) {

    int counter = 0;
    for(int i=1;i<=size;i++){
        harr[i]=arr[i-1];
        heap_size++;
    }
    for (int iterate = heap_size/2;iterate >= 1;iterate--){
        MaxHeapify(iterate,counter);
    }
    cout<<"The number of heapify calls from build heap: "<<counter<<"\n";
}

// Constructor: Builds a heap from a given array a[] of given size
MaxHeap::MaxHeap(int cap, int arr[], int size)
{
    heap_size = 0;
    capacity = cap;
    harr = new int[cap+1];
    buildHeap(arr,size);
    cout<<"This is the original max heap:\n";
    printHeap();
    cout<<"\nHeap commands:\n";
}

// Inserts a new key 'k'
void MaxHeap::insertKey(int k)
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

    // Fix the max heap property if it is violated
    while (i > 1 && harr[parent(i)] < k)
    {
        harr[i] = harr[parent(i)];
        i = parent(i);
    }
    harr[i] = k;
    cout<<"After insert:\n";
    printHeap();
}

// Increases value of key at index 'i' to new_val.  It is assumed that
// new_val is smaller than harr[i].
void MaxHeap::increaseKey(int i, int new_val)
{
 if(new_val<harr[i]){
        cout<<"Error: new key is smaller than current\n";
        printHeap();
        return;
    }
    cout<<"increaseKey("<<i<<","<<new_val<<")\n";
    harr[i] = new_val;
    while (i > 1 && harr[parent(i)] < harr[i])
    {
        swap(&harr[i], &harr[parent(i)]);
        i = parent(i);
    }
    cout<<"After increaseKey:\n";
    printHeap();
}

// Method to remove maximum element (or root) from max heap
void MaxHeap::extractMax()
{
    cout<<"extractMax()\n";
    int counter = 0;
    if (heap_size < 1){
        cout<<"Heap is empty \n";
    }
    // Store the maximum value, and remove it from heap
    int root = harr[1];
    harr[1] = harr[heap_size];
    heap_size--;
    MaxHeapify(1,counter);
    cout<<"The number of heapify calls from extractMax: "<<counter<<"\n";
    cout<<"Deleted key: "<<root<<"\n";
    printHeap();
}

void MaxHeap::printHeap() {
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
void MaxHeap::MaxHeapify(int i, int &counter)
{
    counter++;
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l <= heap_size && harr[l] > harr[i])
        smallest = l;
    if (r <= heap_size && harr[r] > harr[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(&harr[i], &harr[smallest]);
        MaxHeapify(smallest,counter);
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
    MaxHeap h(20, arr, size);

    //************************************************************************
    //Enter commands here
    //Format should be: h.[enter function];

    /*Examples
     * h.insertKey(4);
     * h.extractMin();
     * h.increaseKey(3, 28);
    */
    //************************************************************************
    return 0;
}
