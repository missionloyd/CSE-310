#include <array>
#include <iostream>

//Prints out elements wise comparisons and activation records

using namespace std;

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int Partition(int A[],int p,int r){
    cout<<"Partition("<<p+1<<","<<r+1<<")\n";
    int x = A[r];
    int i = p-1;
    for (int j = p;j<=r-1;j++){
        cout<<A[j]<<"<="<<x<<"\n";
        if (A[j] <= x){

            i = i+1;
            swap(&A[i],&A[j]);
        }
    }
    swap(&A[i+1],&A[r]);
    return i+1;
}

void QuickSort(int A[], int p, int r){
    cout<<"QuickSort("<<"A,"<<p+1<<","<<r+1<<")\n";
    if(p<r){
        int k = Partition(A,p,r);
        cout<<"k="<<k+1<<"\n";
        QuickSort(A,p,k-1);
        QuickSort(A,k+1,r);
    }
}



int main() {

    //int A[] = {19,16,13,25,22};
    int A[] = {13, 16, 22, 23, 9, 2, 14, 15};
    int n = sizeof(A)/sizeof(A[0]);
    QuickSort(A,0,n-1);
    printArray(A,n);
    return 0;


}
