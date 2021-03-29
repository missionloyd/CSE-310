public class MinHeap {
    private int[] A;
    private int size;

    public void buildMinHeap(int[] arr) {
        size = arr.length;
        this.A = new int[size + 1];

        for (int i = 1; i <= size; i++) {
            this.A[i] = arr[i - 1];
        }
        for (int i = (int) Math.floor(size / 2); i >= 1; i--) {
            minHeapify(i);
        }
    }

    public void minHeapify(int i) {
        int l = getLeft(i);
        int r = getRight(i);
        int smallest;

        if (l <= size && A[l] < A[i]) {
            smallest = l;
        } else {
            smallest = i;
        }

        if (r <= size && A[r] < A[smallest]) {
            smallest = r;
        }

        if (smallest != i) {
            swap(i, smallest);
            minHeapify(smallest);
        }
    }

    public void extractMin() {
        if (size < 1) {
            System.out.print("Error: heap empty\n");
        } else {
            int min = A[1];
            A[1] = A[size];
            size--;
            minHeapify(1);
        }
    }

    public void insert(int key) {
        size++;
        int[] temp = new int[size + 1];
        for (int i = 1; i <= size - 1; i++) {
            temp[i] = A[i];
        }
        A = temp;
        decreaseKey(size, key);
    }

    public void decreaseKey(int i, int key) {
        if (key > A[i] && A[i] != 0) {
            System.out.println("Error: new key is greater than current key");
        }
        A[i] = key;
        while (i > 1 & A[getParent(i)] > A[i]) {
            swap(i, getParent(i));
            i = getParent(i);
        }
    }

    public void heapSort() {
        buildMinHeap(A);
        for (int i = A.length; i >= 2; i--) {
            swap(1, i);
            size--;
            minHeapify(1);
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
        System.out.print("i:\t");
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