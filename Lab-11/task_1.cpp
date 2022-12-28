#include <iostream>
#include <vector>
using namespace std;

#define SIZE 100

int hashFunction(int number){
    int x = number%SIZE;
    return x;
}
bool checkSubset(int *array, int position, vector<int>table){
    
    for (int i=0; i<table.size(); i++){
        if (array[position]==table[i]){
           return true;
        }
    }
    return false;
}


int main(){
    cout << "Enter size of initial array: ";
    int size;
    cin >> size;
    vector<vector<int>>hashTable(SIZE);
    int *array = new int[size];
    cout << "Enter numbers of array (" << size << " numbers): ";
    for (int i=0; i< size; i++){
        int x; 
        cin >> x;
        array[i]=x;
        int position= hashFunction(x);
        hashTable[position].push_back(x);
    }
    cout << "Enter size of array to check: ";
    int size1; cin >>size1; 
    int *arrayToCheck = new int[size1];
    cout << "Enter numbers of array to check (" << size1 << " numbers): ";
    for (int i=0; i< size1; i++){
        int x; 
        cin >> x;
        arrayToCheck[i]=x;
    }
    bool check = false;
    for (int i=0; i<size1; i++){
        check = checkSubset(arrayToCheck, i, hashTable[hashFunction(arrayToCheck[i])]);
        if (check==false){
            break;
        }
    }
    cout << "Original array: {";
    for (int i=0;i<size;i++){
        cout << array[i] << ", ";
    }
    cout << "}" << endl;
        cout << "Array to check: {";
    for (int i=0;i<size1;i++){
        cout << arrayToCheck[i] << ", ";
    }
    cout << "}" <<endl;
    if (check==false){
        cout<<"No, the array is not a subset of the original array" << endl;
    }
    else
    cout<<"Yes, the array is a subset of the original array" << endl;
    return 0;
}