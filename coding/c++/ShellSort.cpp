#include<iostream>
using namespace std;

class student{
   public :
    int roll_no;
    string name;
   // public:
    void Sort(student s[],int n);
    void getdata(student s[],int n);
    void  show(student s[],int n);
};
void student ::Sort(student s[],int n){
       int gap=n/2;
       while (gap >= 1) {
            for (int j = gap; j < n; j++) {
                for (int i = j - gap; i >= 0; i -= gap) {  
                    if (s[i + gap].name >  s[i].name) {  
                        break;
                    } else {
                        student temp;
                        temp = s[i + gap];
                        s[i + gap] = s[i];
                        s[i] = temp;
                    }
                }
            }
       }
}
void student::getdata(student s[],int n){
    for(int i=0;i<n;i++){
    cin>>s[i].roll_no>>s[i].name;
    }

        
 }

void student:: show(student s[],int n){
    for(int i=0;i<n;i++)
    cout<<s[i].name<<" "<<s[i].roll_no<<endl;

} 







int main(){
    int n = 3;
    student s[n],t;
   // string[100];
   
    n =sizeof(s)/sizeof(s[0]);

    int choice = 1;

    switch(choice)
    {
        case 1:
        t.getdata(s,n);
        t.Sort(s,n);
        t.show(s,n);
        break;


        
    }


  }
