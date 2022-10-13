#include <iostream>
using namespace std;
struct member{
    string name;
    int age;
    double salary;
};

void assignData(struct member &m){
cout << "Enter name: ";
cin >> m.name;
cout << "Enter age: ";
cin >> m.age;
cout << "Enter salary: ";
cin >> m.salary;
}
void printData(struct member &m){
    cout << "Name: " << m.name << endl << "Age: " << m.age << endl << "Salary: " << m.salary;
}
int main(){
member s;
assignData(s);
printData(s);
    return 0;
}

