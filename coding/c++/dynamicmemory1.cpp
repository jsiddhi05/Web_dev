#include<iostream>
using namespace std;
int main()
{

    int *array=new int[10];
    cout<<"enter the 10 numbers:"<<endl;
    for(int i=0;i<10;i++)
    {
        cin>>array[i];
    }
    
    cout<<"values in dynamically allocated array: "<<endl;
    for(int i=0;i<10;i++)
    {
        cout<<array[i]<<" ";
    }
    
    delete[] array;
    array=NULL;
    
    return 0;
}
