#include "Node.h"

template <class T>
class Queue{
    private: 
    Node<T> *head;
    Node<T> *tail;
    public:
    Queue(){
        head=tail=nullptr;
    }
    void enqueue(T value){
        Node<T> *newNode = new Node(value);
        if (head==nullptr){
            head=tail = newNode;
            
        }
        else if(head!=nullptr){
            newNode ->prev = tail;
            tail->next = newNode;
            tail = tail->next;
        }

    }
    void dequeue(){
        if (head==nullptr){
            cout << "Queue is empty" << endl;
        }
        else {
            Node<T> *tempPtr = head;
            head = head->next;
            delete tempPtr;
        }
    }

    void reverse(int c){
        int count = 0;
        Node <T> *end = head;
        Node <T> *start = head;
        while (count < c -1){
            end = end ->next;
            count ++;
        }
        while (start!=end && start !=end->next){
            T data;
            data = start->data;
            start->data = end->data;
            end->data = data;
            start = start->next;
            end = end->prev;
        }
    }

    void interLeaf (){
        int count = 0;
        Node <T>*temp = head;
        while (temp->next!=nullptr){
            temp = temp->next;
            count ++;
        }
    int halfPoint = count/2;
    Node <T> *start = head;
    Node<T> *halfwayPoint = head;   
    int tillHalfPoint = 0;
    while (tillHalfPoint < halfPoint){
        halfwayPoint = halfwayPoint->next;
        tillHalfPoint++;
    }
    halfwayPoint = halfwayPoint->next;
    
    while (halfwayPoint -> next != nullptr){
        Node <T> *temp = halfwayPoint;
        halfwayPoint = halfwayPoint->next;
        temp->next = start->next;
        temp->prev=start;
        start->next->prev=temp;
        start->next = temp;
        start=temp->next;
         
    }
    start->next = halfwayPoint;

    
    }

    void displayAll(){
        Node<T>* temp = head;
        while (temp!=nullptr){
            cout << temp->data << " ";
            temp=temp->next;
        }
        cout << endl;
    }
    ~Queue() {
        
        while (head!=nullptr){
            dequeue();
        }
    }
};
