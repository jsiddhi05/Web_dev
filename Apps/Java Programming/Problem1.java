import java.util.*;
public class Problem1 {
    public static void main(String args[]){
       // int arr[]={1,0,1,0,1,0,0,1};
       int arr[]= {9,-3,5,-2,-8,-6,1,3};

        for(int i=0;i<arr.length;i++){
            int curr =arr[i];
            int j=i-1;
            while(j>=0 && arr[j]>curr){
                arr[j+1]=arr[j];
                j--;

            }
            arr[j+1]=curr;

        }
        for(int i=0;i<arr.length;i++){
            System.out.println(arr[i]+" ");

        }

    }
    
}

