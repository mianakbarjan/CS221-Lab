#include <iostream>
#include <math.h>
using namespace std;
int main(){
    int rows = 5;
    int columns = 5;

    int **dynamicArray = new int *[rows];
    for (int r=0; r<rows; r++){
        dynamicArray[r]= new int [columns];
    }
    for (int r=0; r<rows; r++){
        for (int c=0; c<columns; c++){
            dynamicArray[r][c]= rand()%10;
        }
    }
    for (int r=0; r<rows; r++){
        for (int c=0; c<columns; c++){
            cout << dynamicArray[r][c] << " ";
        }
    } 

    
    }