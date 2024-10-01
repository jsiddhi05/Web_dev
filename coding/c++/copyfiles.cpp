#include<iostream>
#include<fstream>
using namespace std;

int main(){
    
    ifstream fin;
    ofstream fout;
    
    string line;

    fin.open("copy1.txt");
    fout.open("copy2.txt");
    while(getline(fin, line)){

        
        fout<<line;
}
fin.close();
fout.close();
     return 0;


    



}