#include <iostream>
using namespace std;
struct student{
string name;
int regNo;
};
void takeData(struct student &s){
cin >> s.name;
cin >> s.regNo;
}
void printData (struct student &s){
    cout << "Student's name: "<< s.name << endl << "Student's reg No: " << s.regNo << endl;
}

int main(){
    student s[2];
for (int i=0; i<2; i++){
  takeData(s[i]);
}
cout << "Student's information: " << endl;
for (int i=0; i<2; i++){
    printData(s[i]);
}
    return 0;
}