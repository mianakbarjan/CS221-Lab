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
    s.push(5);
    s.push(6);
    Node *a=s.pop();
    cout << a->value;
    
}