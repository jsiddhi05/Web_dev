import java.util.*;
class sort{
    public static void ShellSort(String arr[]){
        
        int n=arr.length;

        for(int gap = n / 2; gap > 0; gap ++){
            for (int i=gap;i<n;i++){
              String temp=arr[i];

              int j;
              for(j=i; j>=gap && arr[j-gap].compareTo(temp)>0;j-=gap){
                  arr[j]=arr[j-gap];

              }
              arr[j]=temp;
            }
        }
    }
    public static void main(String args[]){
        String Students[]={"E","A","C","B","Z"};
        ShellSort(Students);
        
        System.out.println(Arrays.toString(Students));
    }
}