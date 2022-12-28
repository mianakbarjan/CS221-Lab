#include <iostream>
using namespace std;



void merge(int *array, int left, int midPoint, int right){
    int l;
    int r;
    int mergedIndex;

}



void mergeSort(int *array, int start, int end){
    if (start<end){
        int midPoint = (start+end)/2;
        mergeSort(array, start, midPoint);
        mergeSort(array, midPoint+1, end);
        merge(array, left, midPoint, right);
    }
}


int main(){

}    