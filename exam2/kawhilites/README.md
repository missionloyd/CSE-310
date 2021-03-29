Enter the values from the array into numbers.txt in the same format as project2 HEAPinput.txt. The values are added to a heap.

Go to main.cpp and edit it for union, link, or findSet.
Union:
The format is "Union(int, int, heap);".

findset:
The format is "int a = findSet(int, heap);". findSet returns an integer. Setting equal to "a" prevents an error.

link:
The format is "link(int, int, heap);".

printHeap(heap) will show the array.

After changing main.cpp, do "make" in the terminal to update changes then "./run"
Union, link, findset were modified to work with heaps instead of a regular array.
The logic for each function should still be the same. 
I've tested the code with HW3 and some examples online. 

