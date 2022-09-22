#include <iostream>
#include<string>
using namespace std;

struct student {
int rollNo;
string name;
int age;
string address;
};
//checks students with age 14 and prints their name
void age14(student *s){
    int i=0;
    do {
        if (s[i].age==14){
cout << "Student name: " << s[i].name << endl;
        }
i++;
    }while (s[i].age);
}
//checks students with even rollNo.s and prints their names
void even(student *s){
    int i=0;
    do {
if (s[i].rollNo%2==0){
    cout << "Student name: " << s[i].name << endl;
}
i++;
    }while (s[i].rollNo);
}
//takes in a rollNo and finds it in list
void rollNum(student *s, int size){
    cout << "Enter roll number to find: ";
int num;
cin >> num;
    int i=0;
    do{
        if (s[i].rollNo==num){
            cout << "Student's name: " << s[i].name << endl;
            cout << "Student's rollNo: " << s[i].rollNo << endl;
            cout << "Student's age: " << s[i].age << endl;
            cout << "Student's address: " << s[i].address << endl;
        }
        i++;
    }while (i<size);
}
int main(){
    int size = 1;
    student *s = new student [size];
    char option;
    cout << "Student Roll No.: ";
cin >> s[0].rollNo;
cin.ignore();
cout << "Student Name: ";
getline(cin, s[0].name);
cout << "Student Age: ";
cin >> s[0].age;
if (s[0].age<11 || s[0].age>14){
    cout <<"Enter age again: ";
    cin >> s[0].age;
}
cin.ignore();
cout << "Student Address: ";
getline(cin,s[0].address);
do {
cout << "Do you want to add a new student: ";
cin >> option;
if (option=='y' || option == 'Y'){
    size++;
    student *temp = new student [size];
    for (int i=0; i<size-1; i++){
        temp[i].rollNo= s[i].rollNo;
        temp[i].name= s[i].name;
        temp[i].age= s[i].age;
        temp[i].address= s[i].address;
    }
delete []s;
s=temp;
cout << "Enter details of student " << size << ": ";
cout << "Student Roll No.: ";
cin >> s[size-1].rollNo;
cin.ignore();
cout << "Student Name: ";
getline(cin, s[size-1].name);
cout << "Student Age: ";
cin >> s[size-1].age;
if (s[size-1].age<11 || s[size-1].age>14){
    cout <<"Enter age again: ";
    cin >> s[size-1].age;
}
cin.ignore();
cout << "Student Address: ";
getline(cin, s[size-1].address);
}
else {break;}

}while (option!='n' || option!='N');

age14(s);
even(s);

rollNum(s, size);
return 0;
}