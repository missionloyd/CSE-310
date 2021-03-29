public class MaxHeap {
    private int[] A;
    private int size;

    public void buildMaxHeap(int[] arr) {
        size = arr.length;
        this.A = new int[size + 1];

        for (int i = 1; i <= size; i++) {
            this.A[i] = arr[i - 1];
        }
        for (int i = (int) Math.floor(size / 2); i >= 1; i--) {
            maxHeapify(i);
        }
    }

    public void maxHeapify(int index) {
        int left = getLeft(index);
        int right = getRight(index);
        int largest;

        if (left <= size && A[left] > A[index]) {
            largest = left;
        } else {
            largest = index;
        }

        if (right <= size && A[right] > A[largest]) {
            largest = right;
        }

        if (largest != index) {
            swap(index, largest);
            maxHeapify(largest);
        }
    }

    public void extractMax() {
        if (size < 1) {
            System.out.print("Error: heap empty\n");
        } else {
            int max = A[1];
            A[1] = A[size];
            size--;
            maxHeapify(1);
        }
    }

    public void insert(int key) {
        size++;
        int[] temp = new int[size + 1];
        for (int i = 1; i <= size - 1; i++) {
            temp[i] = A[i];
        }
        A = temp;
        increaseKey(size, key);
    }

    public void increaseKey(int i, int key) {
        if (key < A[i] && A[i] != 0) {
            System.out.println("Error: new key is smaller than current key");
        }
        A[i] = key;
        while (i > 1 & A[getParent(i)] < A[i]) {
            swap(i, getParent(i));
            i = getParent(i);
        }
    }

    public void heapSort() {
        buildMaxHeap(A);
        for (int i = A.length; i >= 2; i--) {
            swap(1, i);
            size--;
            maxHeapify(1);
        }
    }

    public void swap(int a, int b) {
        int temp = A[a];
        A[a] = A[b];
        A[b] = temp;
    }

    private int getParent(int index) {
        return (int) Math.floor(index / 2);
    }

    private int getLeft(int index) {
        return (2 * index);
    }

    private int getRight(int index) {
        return (2 * index + 1);
    }

    public void printArr() {
        System.out.print("i:\t\t");
        for (int x = 1; x <= size; x++) {
            System.out.print("\t" + x);
        }
        System.out.print("\nA[i]:\t");
        for (int x = 1; x <= size; x++) {
            System.out.print("\t" + A[x]);
        }
        System.out.print("\n");
    }
}