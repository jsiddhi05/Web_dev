import java.util.*;

class QuickSort {
    public void qs(int arr[], int F, int L) {
        if (F < L) {
            int pivotIndex = partition(arr, F, L);
            qs(arr, F, pivotIndex - 1);
            qs(arr, pivotIndex + 1, L);
        }
    }

    private int partition(int arr[], int F, int L) {
        int pivot = arr[F];
        int i = F;
        int j = L;

        while (i < j) {
            while (i <= L && arr[i] <= pivot) {
                i++;
            }
            while (j >= F && arr[j] > pivot) {
                j--;
            }
            if (i < j) {
               
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        
        int temp = arr[F];
        arr[F] = arr[j];
        arr[j] = temp;

        return j;
    }

    public static void main(String args[]) {
        QuickSort Q = new QuickSort();

        int arr[] = {12, 11, 13, 5, 6, 7};
        int F = 0;
        int L = arr.length - 1;
        Q.qs(arr, F, L);

        
        System.out.println("Sorted array:");
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
    }
}
