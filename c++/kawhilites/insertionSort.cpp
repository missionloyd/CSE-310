// c++ program for insertion sort 
#include <iostream> 
using namespace std;

/* function to sort an array using insertion sort*/
void insertionsort(int arr[], int n)
{
	int i, key, j;
	for (j = 1; j < n; j++)
	{
		key = arr[j];
		i = j - 1;

		/* move elements of arr[0..i-1], that are
		greater than key, to one position ahead
		of their current position */
		while (i >= 0 && arr[i] > key)
		{
			cout << "Element wise comparison: " << endl << arr[i] << " > " << key << endl;
			cout << "array at index " << i + 1 << " overwritten with " << arr[i] << endl;
			arr[i + 1] = arr[i];
			cout << "current array: ";
			for (int a = 0; a < n; a++)
				cout << arr[a] << " ";
			cout << endl;
			i = i - 1;
		}
		cout << "array at index " << i + 1 << " overwritten with " << key << endl;
		arr[i + 1] = key;
		cout << "current array: ";
		for (int a = 0; a < n; a++)
			cout << arr[a] << " ";
		cout << endl;
	}
}

// a utility function to print an array of size n 
void printarray(int arr[], int n)
{
	int x;
	for (x = 0; x < n; x++)
		cout << arr[x] << " ";
	cout << endl;
}

/* driver code */
int main()
{
	int arr[] = { 13, 14, 11, 15, 12 };
	int n = sizeof(arr) / sizeof(arr[0]); // array size

	insertionsort(arr, n);
	printarray(arr, n);

	return 0;
}

// this is code is contributed by rathbhupendra 