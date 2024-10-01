#include<iostream>
#include<fstream>
using namespace std;

int main(){


       ofstream outf("sample1.txt");

       cout<<"Enter item name";
       char name[30];
       cin>>name;

       outf<<name<<"\n";

       cout<<"Enter item cost";
       float cost;
       cin>>cost;

       outf<<cost<<"\n";

       outf.close();
       
       ifstream inf("sample1.txt");
       inf>>name;
       inf>>cost;
       cout<<"\n";
       cout<<"Item:"<<name<<"\n";
       cout<<"Item cost:"<<cost<<"\n";
       inf.close();
       return 0;
       
}