

public class Heaps {

    public static void main(String[] args) {
        int[] arr = new int[]{
                // insert array contents here
                11, 13, 15, 17, 19, 21, 23, 25, 27, 29
        };

        // if it is MinHeap
        MinHeap heap = new MinHeap(); heap.buildMinHeap(arr);

        // if it is MaxHeap ---> comment the line above, and uncomment the line below
        // MaxHeap heap = new MaxHeap(); heap.buildMaxHeap(arr);

        // insert commands here
        heap.insert(9);


        heap.printArr();
    }

}