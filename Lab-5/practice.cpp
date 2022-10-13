#include "Queue.h"
void menu(){
    cout << "1. Enqueue" << endl;
    cout << "2. Dequeue" << endl;
    cout << "3. Display All" << endl;
    cout << "0. Exit" << endl;
    cout << "Enter Option: ";
}

int main(){
    Queue<int> q;
    int option;
    do {
        menu();
        cin >> option;
        switch (option){
            case 1: {
                int insertValue;
                cout << "Enter value to enter: ";
                cin >> insertValue;
                q.enqueue(insertValue);
                break;
            }
            case 2:{
                q.dequeue();
                break;
            }
            case 3:
            {
                q.displayAll();
                break;
            }
            case 0: 
            {
                break;
            }
            default:{
                cout << "Enter correct value: ";
            }

        }
    }while (option!=0);
    return 0;
}