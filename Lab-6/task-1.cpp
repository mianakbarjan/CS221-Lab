/*
Name: Mian Akbar Jan
Reg No: 2021295
*/

#include <iostream>
using namespace std;

void read(int arr[], int n){
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
}
void print (int arr[], int n){
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
void convert(int *arr, int n){
int i, j, key;
   for (i=2; i<n; i+=2){
    key = arr[i];
    j=i-2;
    while (j>=0 && arr[j] < key){
        arr[j+2] = arr[j];
        j-=2;
   }
   arr[j+2] = key;
   }
   for (i=3; i<n; i+=2){
    key = arr[i];
    j=i-2;
    while (j>=0 && arr[j]>key){
        arr[j+2] = arr[j];
        j-=2;
    }
    arr[j+2]=key;
   }
}

int main(){
cout << "Enter number of elements: ";
int elem; cin >> elem;
int *array = new int [elem];
cout << "Enter all values: ";
read(array, elem);
cout << "Unsorted array: ";
print (array, elem); //prints original array
cout << "After performing operation (odd in descending and even in ascending): ";
convert(array, elem); //converts array
print (array, elem); //prints array after performing function
return 0;
}