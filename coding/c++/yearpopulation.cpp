#include<iostream>
using namespace std;
int main(){
int i;    
int year[4];
int population[4];
cout<<"Enter 4 Years:"<<endl;
for(int i=0;i<4;i++){
    cin>>year[i];
}    
cout<<"Enter Population for 4 Years"<<endl;
for(int i=0;i<4;i++){
    cin>>population[i];
}
cout<<"Years"<<"  "<<"population"<<endl;
for(int i=0;i<=3;i++){
    cout<<year[i]<<"  "<<population[i]<<endl;
}



    return 0;
}