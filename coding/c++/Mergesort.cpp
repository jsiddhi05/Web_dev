#include<iostream>
using namespace std;
class Mergesort{
    void mergesort(int a[],int l, int r);
    void print(int a[],int l, int r);
    void merge(int a[],int l, int r);

    int main(){
        int a[8]={23,50,10,12,5,20,1};
        int l=0;
        int r=6;

        mergesort(a,l,r);
        print(a,l,r);

        return 0;

    }
    void mergesort(int a[],int l, int r){
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
            cout<<a[i];
        }
    }

    void merge(int a[],int l,int r,int mid){
        int n1=mid+1;
        int n2=r-mid;

        int L[n1],int[n2];
        for(i=0;i<n1;i++){
            
        }
        }

        
        
    }
    


};