#include <iostream>
using namespace std;

class linkedList {
private:
    struct Node {
        int value;
        Node* next;
    };
    Node* headPointer;

public:
    linkedList() {
        headPointer = NULL;
    }
    void addNodeAtHead(int a) {
        Node* newNode = new Node;
        newNode->value = a;
        newNode->next = headPointer;
        headPointer = newNode;
    }

    void addNodeAtTail(int a) {
        Node* temp = headPointer;
        Node *newNode = new Node;
        newNode->value = a;
        newNode->next = NULL;
        if (headPointer==NULL){
            headPointer=temp;
            return;
        }
        while (temp->next != NULL) {
            temp = temp->next;
        }
        
    }
    
    void makeCycle(){
        Node *temp = headPointer;
        while (temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=headPointer;
        cout << "Cycle created" << endl;
    }

    void detectCycle(){
        Node *temp = headPointer;
        while (temp->next!=headPointer && temp->next !=NULL){
            temp= temp->next;
        }
        if (temp->next==headPointer){
                cout << "Cycle detected";
                return;
            }
            else{
                cout << "No cycle detected" << endl;
            }
    }

    void removeCycle(){
        Node *temp = headPointer;
        while (temp->next!=headPointer){
            temp=temp->next;
        }
        temp->next = NULL;
        cout << "Cycle removed" << endl;
    }

    void displayAll() {
        Node* temp = headPointer;
        while (temp != NULL) {
            cout << temp->value << ", ";
            temp = temp->next;
        }
    }

    ~linkedList(){
        Node *deleteNode;
        while (headPointer!=NULL){
            deleteNode = headPointer;
            headPointer = headPointer -> next;
            delete deleteNode;
        }
    }
};
int main (){
    linkedList List;
    List.addNodeAtTail(1);
    List.addNodeAtTail(2);
    List.addNodeAtTail(3);
    List.addNodeAtTail(4);
    List.detectCycle();
    List.displayAll();

}