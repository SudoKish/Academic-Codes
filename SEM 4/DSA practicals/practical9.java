

//Implement the Heap/Shell sort algorithm implemented in Java demonstrating heap/shell data structure with 
//modularity of programming language.



import java.util.Scanner;

public class dsa_practical9 {
    public int[] heap;
    public int count;

    public void downadjust(int i) {
        int j, temp, n;
        n = heap[0];
        if (2 * i <= n) {
            j = 2 * i; // j on left child of i
            if (j + 1 <= n && heap[j + 1] > heap[j]) // j points to larger of left and right child
                j = j + 1;
            if (heap[i] < heap[j]) {
                temp = heap[i];
                heap[i] = heap[j];
                heap[j] = temp;
                downadjust(j);
            }
        }
    }

    public void upadjust(int i) {
        int temp;
        while (i > 1 && heap[i] > heap[i / 2]) {
            temp = heap[i];
            heap[i] = heap[i / 2];
            heap[i / 2] = temp;
            i = i / 2;
        }
    }

    public void insert(int x) {
        heap[++heap[0]] = x;
        upadjust(heap[0]);
    }

    public void create() {
        int i, x, n;
        heap = new int[30];
        heap[0] = 0;
        try (Scanner reader = new Scanner(System.in)) {
            System.out.println("\nEnter No. of elements : ");
            n = reader.nextInt();
            count = n;
            System.out.println("\nEnter heap data : ");
            for (i = 0; i < n; i++) {
                x = reader.nextInt();
                insert(x);
            }
        }
    }

    public void sort() {
        int last, temp;
        while (heap[0] > 1) {
            last = heap[0];
            temp = heap[1];
            heap[1] = heap[last];
            heap[last] = temp;
            heap[0]--;
            downadjust(1);
        }
    }

    public void print() {
        int n, i;
        n = count;
        System.out.println("\nsorted data : ");
        for (i = 1; i <= n; i++)
            System.out.print("" + heap[i]);
    }

    public static void main(String[] args) {
        dsa_practical9 myobject = new dsa_practical9();
        myobject.create();
        myobject.sort();
        myobject.print();
    }
}


/*
Theory:
Heap Sort:
Heap sort is a comparison-based sorting algorithm that builds a heap from the input data and then repeatedly extracts the maximum element from the heap and places it at the end of the sorted array.
It has a time complexity of O(n log n) and is in-place, meaning it does not require additional memory.
Shell Sort:
Shell sort is an optimization of insertion sort that starts by sorting pairs of elements far apart from each other, then progressively reduces the gap between elements to be compared.
It has a time complexity of O(n log n) in the worst case but can perform better than O(n^2) algorithms like insertion sort.
Implementation:
Modular Functions:
Implement separate functions or classes for heap sort and shell sort to encapsulate the sorting logic.
Each function or class should accept an array of elements to be sorted and return the sorted array.
Heap Data Structure:
Implement the heap data structure, either as a separate class or within the sorting algorithm itself, to build and maintain the heap property.
Shell Data Structure:
Implement the shell data structure, typically as a gap sequence, which determines the intervals at which elements are compared and swapped.
Time and Space Complexity:
Heap Sort:
Time Complexity: O(n log n) for both best and worst cases.
Space Complexity: O(1) as it sorts in-place.
Shell Sort:
Time Complexity: O(n log n) in the worst case, but can vary depending on the gap sequence chosen.
Space Complexity: O(1) as it sorts in-place.
Real-World Considerations:
Optimization:
Choose an appropriate gap sequence for Shell Sort to optimize its performance.
Use a binary heap for Heap Sort to reduce constant factors and improve performance.
Stability:
Consider the stability of the sorting algorithms. Shell sort is generally not stable, while heap sort can be made stable with additional bookkeeping.
Memory Usage:
Ensure that the algorithms are memory-efficient, especially for large datasets, by minimizing auxiliary memory usage.
Conclusion:
Implementing the Heap or Shell Sort algorithm in Java with a modular approach allows for flexibility and maintainability. Encapsulating sorting logic within separate functions or classes promotes code reuse and readability. By understanding the time and space complexity of each algorithm and considering real-world factors like stability and memory usage, we can choose the most appropriate sorting algorithm for a given scenario.
 */