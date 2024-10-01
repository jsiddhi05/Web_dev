#include<iostream>
using namespace std;
int main() {
    int n,m, i,j;  //n for row and m for column ,i,j for loop 
    cin>>n;
    cin>>m;

    for (i=1;i<=n;i++){ //to print n rows 1 to n

       for(j=1;j<=m;j++){ //to print m columns 1 to m

        cout<<"  "<<"*";

       }

       cout<<endl;
    }

    return 0;
        
}