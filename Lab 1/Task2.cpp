#include <iostream>
using namespace std;

int main()
{
    int array[5];
    for (int count=0; count < 5; count++){
        cin>>array[count];
    }
    int *pointer = array;
    int sum = 0;
    for (int count=0; count < 5; count++){
        sum+= *(pointer+count);
    }
    cout << "Sum: " << sum;

}