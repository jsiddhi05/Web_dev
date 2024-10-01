#include <iostream>
using namespace std;
int main() {
 int n;
 cout << "Enter the number of students: ";
 cin >> n;
 
 float *CGPA = new float[n];
 cout << "Enter the CGPAs of " << n << " students: "<<endl;
 for (int i = 0; i < n; ++i) {
 cout << "Student " << i + 1 << ": ";
 cin >> CGPA[i];
 }
 
 cout << "CGPA of the students:"<<endl;
 for (int i = 0; i < n; ++i) {
 cout << "Student " << i + 1 << ": " << CGPA[i] << endl;
 }
 
 delete[] CGPA;
 
 return 0;
}