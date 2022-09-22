#include <iostream>
#include<string>
using namespace std;

struct student {
int rollNo;
string name;
int age;
string address;
void enterData(){
     cout << "Student Roll No.: ";
cin >> rollNo;
cin.ignore();
cout << "Student Name: ";
getline(cin, name);
cout << "Student Age: ";
cin >> age;
if (age<11 || age>14){
    cout <<"Enter age again: ";
    cin >> age;
}
cin.ignore();
cout << "Student Address: ";
getline(cin, address);
}
};
//checks students with age 14 and prints their name
void age14(student *s, int size){
    int i=0;
    do {
        if (s[i].age==14){
cout << "Student name: " << s[i].name << endl;
        }
i++;
    }while (i<size);
}
//checks students with even rollNo.s and prints their names
void even(student *s, int size){
    int i=0;
    do {
if (s[i].rollNo%2==0){
    cout << "Student name: " << s[i].name << endl;
}
i++;
    }while (i<size);
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
    s[size-1].enterData();

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
s[size-1].enterData();
}
else {break;}

}while (option!='n' || option!='N');

age14(s, size);
even(s, size);

rollNum(s, size);
return 0;
}