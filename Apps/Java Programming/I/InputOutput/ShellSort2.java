import java.util.*;

class ShellSort2 {
    public static void main(String args[]) {  
        int n = 4;
        int arr[] = new int[n];

        arr[0] = 4;
        arr[1] = 3;
        arr[2] = 6;
        arr[3] = 2;  

        int gap = n / 2;

        while (gap >= 1) {
            for (int j = gap; j < n; j++) {
                for (int i = j - gap; i >= 0; i -= gap) {  // Corrected loop initialization
                    if (arr[i + gap] >= arr[i]) {  // Corrected condition check
                        break;
                    } else {
                        int temp;
                        temp = arr[i + gap];
                        arr[i + gap] = arr[i];
                        arr[i] = temp;
                    }
                }
            }
            gap = gap / 2;
        }

        for (int i = 0; i < n; i++) {
            System.out.println(arr[i]);
        }
    }
}
