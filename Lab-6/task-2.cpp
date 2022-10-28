/*
Name: Mian Akbar Jan
Reg No: 2021295
*/

#include <iostream>
using namespace std;

struct Date{
int day;
int month;
int year;
int totalValue; //total equivalent of the date in days format, i.e. (year*365 + month*30 + days)

void read(){ 
    do {
        cout << "Enter day: ";
    cin >> day;
        if (day>31 || day <1){
            cout << "Invalid day!" << endl;
        }
    }while (day>30 || day <1);
    do {
        cout << "Enter month: ";
        cin >> month;
        if (month>12 || month <1){
            cout << "Invalid month!" << endl;
        }
    }while (month>12 || month <1);
    cout << "Enter year: ";
    cin >> year;
    totalValue = (year*365)+(month*30)+day;
}
void print ()
    {
        cout << day << "/" << month << "/" << year << endl;
    }
};
void swap (Date &date1, Date &date2){
    Date temp = date1;
    date1 = date2;
    date2 = temp;
}
void selectionSort(Date *dates, int size){
    int minimumIndex;;
    for (int i=0; i<size-1 ; i++){
        minimumIndex= i;
    for (int j = i+1; j < size; j++){
    if (dates[j].totalValue < dates[minimumIndex].totalValue){
        minimumIndex = j;
        }
    }
    swap(dates[minimumIndex], dates[i]);    
}
}

int main(){
    cout << "Enter number of dates that you want to enter: ";
    int max;
    cin >> max;
    Date *dates = new Date[max];
    for (int i=0; i<max; i++){
        dates[i].read();
    }
    cout << endl << "Before selection sort: " << endl;
    for (int i=0; i<max; i++){
        cout << i+1 << ". ";
        dates[i].print();
    }
    selectionSort(dates, max);
    cout << endl << "After selection sort: " << endl;
    for (int i=0; i<max; i++){
        cout << i+1 << ". ";
        dates[i].print();
    }
}