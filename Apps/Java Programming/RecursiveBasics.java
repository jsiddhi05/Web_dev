public class RecursiveBasics{
    public static void  printDec(int n){
        if(n==1){
            System.out.println(n);
            return ;
        }
         System.out.print(n+" ");
         printDec(n-1);
    }
    public static int fact(int n){
        if(n==0){
            return 1;
        }
        int fnm1=fact(n-1);
        int fn=n*fact(n-1);
        return fn;
    }
    public static int calSum(int n){
        if(n==1){
            return 1;
        } 
        int Snm1=calSum(n-1);
        int Sn= n+ Snm1;
        return Sn;
    }
    //Calculating n fibo numbers in series
    public static int fib(int n){
        if (n==0|| n==1){
            return n;
        }
        int fnm1=fib(n-1);
        int fnm2=fib(n-2);
        int fn = fnm1 + fnm2;
        return fn;

    }
    //check if array is sorted
    public static boolean isSorted(int arr[],int i){
        if (i== arr.length-1){
            return true;
        }
        if (arr[i]>arr[i-1]){
            return false;
        }
        return isSorted(arr, i+1);
    }
    public static int firstOccurence(int arr[],int key,int i){
        if(i==arr.length){
            return -1;
        }
        if (arr[i]==key){
            return i;
        }
        return firstOccurence(arr,key,i+1);
    }
    public static int lastOccurence(int arr[],int key,int i){
        if(i==arr.length){
            return -1;
        }
        int isFound=lastOccurence(arr,key,i+1);
        if(isFound==-1 && arr[i]==key){
            return i;
        }
        return isFound;

    }
    public static int power(int x, int n){
        if(n==0){
            return 1;

        }
        //int xn1=power(x,n-1);
        //int xn= x*xn1;
        //return xn;
        return x*power(x,n-1);
    }



public static void main (String arg[]){
   
    System.out.println(power(2,10));
 }

}
