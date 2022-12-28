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

};

void swap(int* a, int* b)
{
int t = *a;
*a = *b;
*b = t;
}
int partition (int arr[], int low, int high)
{
int pivot = arr[high]; // pivot
int i = (low - 1); // Index of smaller element
for (int j = low; j <= high - 1; j++)
{
// If current element is smaller than or
// equal to pivot
if (arr[j] <= pivot)
{
i++; // increment index of smaller element
swap(&arr[i], &arr[j]);
}
}
swap(&arr[i + 1], &arr[high]);
return (i + 1);
}
/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort(int arr[], int low, int high)
{
if (low < high)
{
/* pi is partitioning index, arr[p] is now
at right place */
int pi = partition(arr, low, high);
// Separately sort elements before
// partition and after partition
quickSort(arr, low, pi - 1);
quickSort(arr, pi + 1, high);
}
}
void convertLinkedListToArray(LinkedList l, int &array){
    
}