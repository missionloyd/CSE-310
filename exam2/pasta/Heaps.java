public class Heaps {

    public static void main(String[] args) {
        int[] arr = new int[]{
                // insert array contents here
                1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11
        };

        // if it is MinHeap --->
        MinHeap heap = new MinHeap(); heap.buildMinHeap(arr);

        // if it is MaxHeap ---> comment the line above, and uncomment the line below
        // MaxHeap heap = new MaxHeap(); heap.buildMaxHeap(arr);


        // insert commands here
        heap.extractMin();



        heap.printArr();
    }

}