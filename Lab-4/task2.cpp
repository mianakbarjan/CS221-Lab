#include <iostream>
using namespace std;
struct Node {
    int value;
    Node *next;
};

class Stack{
private:
Node *top;
public:
Stack(){
    this->top=nullptr;
}
void push(int data){
    Node *newNode = new Node;
    newNode->value= data;
    newNode->next=top;
    top = newNode;
}
Node* pop(){
    
    if (top==nullptr){
        throw invalid_argument("No values");
    }
    
    Node *temp =top;
    top = top->next;
    return temp;
    
}
};



int main(){

int size;
cout << "Enter size of array: ";
cin >> size;
Stack beforeMidPoint;
Stack afterMidPoint;
int *array= new int[size];
for (int i=0; i<size; i++){
    cout << "Enter values: ";
    cin >> array[i];
}
int midpoint = size/2;
for (int i=0; i<midpoint; i++){
    beforeMidPoint.push(array[i]);
}
for (int i=midpoint; i<size; i++){
    afterMidPoint.push(array[i]);
}
cout << "Before midpoint: " << endl;
for (int i=0; i<midpoint; i++){
    Node* temp = beforeMidPoint.pop();
    cout << temp->value << endl;
}
cout << "After midpoint: " << endl;
for (int i=midpoint; i<size; i++){
    Node* temp = afterMidPoint.pop();
    cout << temp->value << endl;
}


}