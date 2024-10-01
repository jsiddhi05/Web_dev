import java.util.*;

public class InsertionSort {
    public static void main(String[] args) {
        int roll_no = 4;
        int arr[] = new int[roll_no];

        arr[0] = 4;
        arr[1] = 3;
        arr[2] = 6;
        arr[3] = 2;

        for (int i = 1; i < roll_no; i++) {
            int curr = arr[i];
            int j = i - 1;

            // Shift elements of arr[0..i-1] that are greater than curr
            // to one position ahead of their current position
            while (j >= 0 && arr[j] > curr) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = curr;
        }

        for (int i = 0; i < roll_no; i++) {
            System.out.print(  arr[i] + " ");
        }
    }
}
