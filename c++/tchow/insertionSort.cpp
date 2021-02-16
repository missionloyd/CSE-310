#include <iostream>

using namespace std;

//Prints out element wise comparisons

/* Function to sort an array using insertion sort*/
void insertionSort(int arr[], int n)
{
    int j, key, i;
    for (j = 1; j < n; j++)
    {
        key = arr[j];
        i = j - 1;

        /* Move elements of arr[0..j-1], that are
        greater than key, to one position ahead
        of their current position */

        while (i >= 0 && arr[i] > key)
        {
            cout<<arr[i]<<">"<<key<<"\n";
            arr[i + 1] = arr[i];
            i = i - 1;

        }
        if(i>=0){   //Avoids printing out of bound comparisons. Since the while loop has 2 conditions we need this 2nd cout.
            cout<<arr[i]<<">"<<key<<"\n";
        }
        arr[i + 1] = key;
    }
}

// A utility function to print an array of size n
void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

/* Driver code */
int main()
{
    int arr[] = { 19,16,13,25,22};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, n);
    printArray(arr, n);

    return 0;
}
