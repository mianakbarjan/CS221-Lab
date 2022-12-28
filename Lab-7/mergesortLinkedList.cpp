using namespace std;
 
#include <iostream>
using namespace std;

class Node {
    private:
    Node *next;
    Node *previous;
    int data;
    
    public:
    Node (int d){
        data = d;
        next = nullptr;
        previous = nullptr;
        
    }
    Node (){
        next = previous = nullptr;
        
    }
friend class LinkedList;
};


class LinkedList{
private:

Node *tail;
int size;
public:
Node *head;
LinkedList(){
    head = tail = nullptr;
    size = 0;
}

void addNodeAtHead(int d){
    Node *newNode = new Node (d);
    newNode->next = head;
    head = newNode;
    size++;
}
void addNodeAtTail (int d){
    Node *temp= head;
    Node *newNode = new Node (d);
if (head==nullptr){
head = newNode;
size++;
return;
}
while (temp->next!=nullptr){
    temp = temp->next;
}
temp->next = newNode;
newNode->previous=temp;
size++;
}
void displayLists(){
    Node *temp = head;
    while (temp!=nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl << size;
}
void Delete(int d){
    Node *temp = head;
    Node *prev = head;
    if (head == nullptr){
        cout << "Cannot delete empty linked list";
        return;
    }
    while (temp->next !=nullptr && temp->data!=d){
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    temp->next->previous = prev;
    size--;
    delete temp;

}
int length(Node *temp){
    Node *traverse = temp;
    int count =0;
    while (temp != nullptr){
        count ++;
        temp = temp->next;
    } 
    return count;
}

void merge(Node *&headPtr, Node *Left, Node *midPoint, Node* Right){
    int i, j, k;
    Node *traverse = Left;
    int countLeft = 1;
    while (traverse!= midPoint->next){
        traverse = traverse->next;
        countLeft ++;
    }
    int countRight = 1;
    traverse = midPoint->next; 
    while (traverse!=nullptr){
        traverse=traverse->next;
        countRight++;
    }
    LinkedList l, r;
    traverse=Left;
    for (i=0; i<= countLeft; i++){
        l.addNodeAtTail(traverse->data);
        traverse=traverse->next;
    }
    traverse= midPoint->next;
    for (j=0; j<=countRight;j++){
        r.addNodeAtTail(traverse->data);
        traverse=traverse->next;
    }
    LinkedList newList;
    Node *traverseLeft = l.head;
    Node *traverseRight = r.head;
    while (traverseLeft!=nullptr && traverseRight!=nullptr){
        if (traverseLeft->data<=traverseRight->data){
            newList.addNodeAtTail(traverseLeft->data);
            traverseLeft=traverse->next;
        }
        else{
            newList.addNodeAtTail(traverseRight->data);
            traverseRight=traverseRight->next;
        }
    }
    while (traverseLeft!=nullptr){
        newList.addNodeAtTail(traverseLeft->data);
    }
    while (traverseRight!=nullptr){
        newList.addNodeAtTail(traverseRight->data);
    }
headPtr = newList.head;
}

void mergeSort(Node *&headPtr, Node* Left, Node* Right){
    Node *traverse = Left;
    int midPoint = length(headPtr)/2;
    int countLeft =1;
    while (countLeft<=midPoint && traverse!=nullptr){
        countLeft++;
        traverse=traverse->next;
    }
    int countRight = 0;
    while (countRight<=length(headPtr)&& traverse!=nullptr){
        countRight++;
        traverse=traverse->next;
    }

    if (countLeft<countRight){
        Node *temp=Left; 
        for (int i=0; i<=midPoint; i++){
            temp=temp->next;
        }
        mergeSort(headPtr, Left, temp);
        mergeSort(headPtr, temp->next, Right);
        merge(headPtr, Left, temp->next, Right);
    }
     
}
void mergeSortHelper(){
    Node *temp = head;
    while (temp->next!=nullptr){
        temp=temp->next;
    }
    mergeSort(head, head, temp);
}

int main(){
    LinkedList l;
    l.addNodeAtTail(5);
    l.addNodeAtTail(4);
    l.addNodeAtTail(6);
    l.addNodeAtTail(3);
    l.addNodeAtTail(7);
    int x= l.length(l.head);
    l.mergeSortHelper();
    l.displayLists();
    cout << x;
}