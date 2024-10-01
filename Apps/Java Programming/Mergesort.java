import java.util.*;
public class Mergesort{
   
    public static void main(String args[]){
        int a[]={23,50,10,12,5,20,1};
        int l=0;
        int r=6;

        mergesort(a,l,r);
        print(a,l,r);

        return ;
    }
    public void mergesort(int a[],int l, int r){
        if(l<r){
            int mid=(l+r)/2;
            mergesort(a,l,mid);
            mergesort(a,mid+1,r);
            merge(a,l,mid,r);
        }
        else
            return;
        

    }
    void print(int a[],int l, int r){
        for (int i=0;i<r;i++){
            System.out.println(a[i]);
        }
    }
    
    void merge(int a[],int low, int mid,int high){
        int temp[];
        int l=low;
        int r=mid+1;
        int i=0;
        while(l<=mid && r<=high){
            if [a[l]<a[r]]{
                temp[i]=a[l];
                l++;
                i++;
            }

        }
        else{
            temp[i]=a[r];
            r++;
            i++;
        }

        while(l<=mid){
            temp=a[l];
            l++;
            i++;
        }    
        


    }
}