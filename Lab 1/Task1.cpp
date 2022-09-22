#include <iostream>
using namespace std;
void swap (int *x, int *y){
    int z = *x;
    *x=*y;
    *y=z;
}
int main()
{
    int num1, num2;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;
    swap(&num1, &num2);
    cout << num1 << endl << num2;
}