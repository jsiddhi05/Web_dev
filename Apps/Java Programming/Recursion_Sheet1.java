public class Recursion_Sheet1{
    public static void linearSearch(int arr[],int key,int start){
        if (start==arr.length) return;
        if (arr[start]==key){
            System.out.println(start);
        }
        linearSearch(arr,key,start+1);

    }

    //using end for the same problem
    public static void LinearSearch(int arr[],int key,int end){
        if (end==arr.length){
            return;
        }
        
        LinearSearch(arr,key,end+1);
        if(arr[end]==key){
            System.out.println(end);
        }
    }

/*public static void main (String arg[]){
    int arr[]={10,20,30,10,20,20};
    int key=20;
    LinearSearch(arr,key,0);
}*/
    public static void towerOfHanoi(int n,String src, String helper, String dest){
        if(n==1){
        System.out.println("transfer disk" + n + "from" + src + "to" + dest);
        return;
        }

        //transfer n-1 from src to helper using dest as 'helper'
        towerOfHanoi(n-1,src,dest,helper);
        //transfer nth from src to dest
        System.out.println("transfer disk"+ n + "from" + src + "to" + helper);
        //transfer n-1 from helper to dest using src as helper
        towerOfHanoi(n-1,helper,src,dest);
    }


public static void main (String arg[]){
    int n=3;
    towerOfHanoi(n,"A","B","C");
    
}
}
