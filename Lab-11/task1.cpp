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
friend class Hash;
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
};




class Hash{
    int bucket; //No. of buckets

    LinkedList *table;

    public:
    //hash function
    int hashFunction(int x){
        return (x%bucket);
    }
    //constructor
    Hash(int V){
        this->bucket = V;
        table = new LinkedList[bucket];
    }
    //insert Item function
    void insertItem(int key){
        int index = hashFunction(key);
        table[index].addNodeAtTail(key);
    }
    //delete Item
    void deleteItem(int key){
        int index = hashFunction(key);
        //find the key
           if (table[index].head==nullptr){
            return;
           }
           else if (table[index].head->data==key){
            table[index].head = table[index].head->next;
            return;
        }
        auto i=table[index].head->next;
        auto j=table[index].head;
        for (i; i!=nullptr; i=i->next){
            j=j->next;
            if (i->data ==key){
                break;
            }
    }
    if (i->next!=nullptr){
        j->next = i->next;
        delete i;
    }
    }
void displayHash() {
for (int i = 0; i < bucket; i++) {
cout << i;
for (auto x : table[i])
cout << " --> " << x;
cout << endl;
}
}
 
};