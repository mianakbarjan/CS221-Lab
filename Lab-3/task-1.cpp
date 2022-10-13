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
        Node* temp = new Node;
        temp = headPointer;
        if (headPointer==NULL){
            headPointer=temp;
            return;
        }
        while (temp->next != NULL) {
            temp = temp->next;
        }
        Node* newNode;
        newNode->value = a;
        temp->next = newNode;
        newNode->next = NULL;
    }
    
    void reverse2Nodes(){
    int count = 0;
    Node *temp = headPointer;
    while (temp->next!=NULL){
        if (count == 0){
            Node *swap = temp->next;
            Node *store = swap->next;
            swap->next=temp;
            temp->next = store;
            headPointer=swap;
            temp = store;
            count ++;
        }
        else{
            Node *swap = temp->next;
            Node *store = swap->next;
            swap->next=temp;
            temp->next = store;
            temp = store;
        }
    }
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

int main() {
    linkedList List;
    List.addNodeAtHead(1);
    List.addNodeAtHead(2);
    List.addNodeAtHead(3);
    List.addNodeAtHead(4);
    List.reverse2Nodes();
    List.displayAll();
    return 0;
}



