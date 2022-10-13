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

    void addMiddle(int a) {
        Node* temp = new Node;
        temp = headPointer;
        int count = 0;
        while (temp->next != NULL) {
            temp = temp->next;
            count++;
        }
        count = count / 2;
        temp = headPointer;
        for (int c = 0; c < count; c++) {
            temp = temp->next;
        }
        Node* newNode = new Node;
        newNode->value = a;
        newNode->next = temp->next->next;
        temp->next = newNode;
    }

    void displayAll() {
        Node* temp = headPointer;
        while (temp != NULL) {
            cout << "HEllo" << temp->value;
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
    List.addMiddle(5);
    List.displayAll();
    return 0;
}