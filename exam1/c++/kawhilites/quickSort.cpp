/* C++ implementation of QuickSort */
#include <iostream> 
using namespace std;

// A utility function to swap two elements 
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
int partition(int arr[], int low, int high)
{
	cout << "partition(arr[], "<< low << ", " << high << ") activation" << endl;
	int pivot = arr[high]; // pivot 
	int i = (low - 1); // Index of smaller element 

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than the pivot 
		cout << "Element-wise comparison: " << arr[j] << " <= " << pivot << endl;
		if (arr[j] <= pivot)
		{
			i++; // increment index of smaller element
			cout << "Swapped arr[" << i << "] = " << arr[i] << " and arr[" << j << "] = " << arr[j] << endl;
			swap(&arr[i], &arr[j]);
		}
	}
	cout << "Swapped arr[" << i+1 << "] = " << arr[i+1] << " and arr[" << high << "] = " << arr[high] << endl;
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort(int arr[], int low, int high)
{
	cout << "quicksort(arr[], " << low << ", " << high << ") activation" << endl;
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		at right place */
		int pi = partition(arr, low, high);

		// Separately sort elements before 
		// partition and after partition 
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

/* Function to print an array */
void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

// Driver Code 
int main()
{
	int arr[] = { 19, 16, 13, 25, 22 };
	int n = sizeof(arr) / sizeof(arr[0]);
	quickSort(arr, 0, n - 1);
	cout << "Sorted array: \n";
	printArray(arr, n);
	return 0;
}

