#include <iostream>
#include <vector>
using namespace std;

#define SIZE 100

int hashFunction(int number){
    int x = number%SIZE;
    return x;
}

int minDeletion(int value, vector<int>table){
    int count = 0;
    for (int i=0; i<table.size(); i++){
        if(table[i]==value){
            count++;
        }    
    }
    return count;
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
    vector<int>countNums;
    for (int i=0; i< size; i++){
        int index = hashFunction(array[i]);
        vector<int> temp = hashTable[index];
        int count=minDeletion(array[i],temp);
        countNums.push_back(count);
    }
    int max=0;
    for(int i=0; i< countNums.size(); i++){
        if (countNums[i]>max){
            max = countNums[i];
        }
    }
    cout << size-max;

    return 0;
}