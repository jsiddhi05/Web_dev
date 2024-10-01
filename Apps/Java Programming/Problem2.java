import java.util.*;
public class Problem2 {

    static void sort(int arr[]){
        int n=arr.length;
        int arr1[]=new int[n];
        int arr2[]=new int[n];
        for(int i=0;i<n;i++){
            if(arr[i]>0){
                arr1[i]=arr[i];
            }
            else{
                arr2[i]=arr[i];
            }
           
        }
        for(int i=0;i<n;i++)
        System.out.print("arr1="+arr1[i]+" ");
        System.out.println();

        

        for(int i=0;i<n;i++)
        System.out.print("arr2="+arr2[i]+" ");
    }
    public static void main(String args[]){
        int arr[]={5,-2,9,-6,1,-8,3,-3};
        sort(arr);
        //for(int i=0;i<arr.length;i++){
        //System.out.print(arr[i]+" ");
        //}

        


    }
    
}
