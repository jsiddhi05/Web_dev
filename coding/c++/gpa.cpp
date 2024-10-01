#include<iostream>
using namespace std;
int main(){
    int n,i;
    cout<<"Enter number of students:";
    cin>>n;
    int *ptr=new int[n];
    for (i=0;i<n;i++)
    {
        cin>>ptr[i];
    }
    cout<<"gpa of students:";
    for (i=0;i<n;i++)
    {
        cout<<ptr[i]<<"\t";
    }
    delete []ptr;
    cout<<endl<<"gpa of students after deletion:";
    for(i=0;i<n;i++)
    {
        cout<<ptr[i]<<"\t";
    }
    ptr=NULL;
    cout<<endl<<"gpa after assigning null value";
    for(i=0;i<n;i++){
       cout<<"\t"<<ptr;
    }

    


}














