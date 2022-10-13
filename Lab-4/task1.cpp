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
    Stack s;
    int array[5];
    for (int i=0; i<5; i++){
        cout << "Enter value: ";
        cin >> array[i];
        s.push(array[i]);
    }
    cout << "Before reverse: ";
    for (int i=0; i<5; i++){
        cout << array[i] << endl;
    }
    cout << "Array in reverse order: " << endl;
    for (int i=0; i<5; i++){
        Node *temp = s.pop();
        cout << temp->value << endl;
    }
    
}