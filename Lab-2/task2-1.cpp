/*Task 2 made using static arrays*/
#include <iostream>
using namespace std;
struct student {
int rollNo;
string name;
int age;
string address;
};

void age14(struct student s[], int size){
    for (int i=0; i<size; i++){
if (s[i].age == 14){
    cout << s[i].name << endl;
}
}
}
void even(struct student s[], int size){
    for (int i=0; i<size; i++){
        if (s[i].rollNo%2==0){
            cout << s[i].name << endl;
        }
    }
}
void rollNo (struct student s[], int size){
    int roll;
    cin >> roll;
    for (int i=0; i<size; i++){
        if (s[i].rollNo==roll){
cout << "Student Name: " << s[i].name << endl;
cout << "Student rollNo: " << s[i].rollNo << endl;
cout << "Student Age: " << s[i].age << endl;
cout << "Student Address: " << s[i].address << endl;
        }
    }
}

int main()
{
student s[1];
for (int i=0; i<1; i++){
    cout << "Enter rollNo:";
cin >> s[i].rollNo;
cout << "Student Name: ";
cin >> s[i].name;
cout << "Student Age: ";
cin >> s[i].age;
if(s[i].age<11 || s[i].age>14){
    cout << "Enter age again: ";
    cin >> s[i].age;
}
cout << "Student Address: ";
cin >> s[i].address;
}

age14(s,1);
even(s, 1);
rollNo(s, 1);
return 0;
}