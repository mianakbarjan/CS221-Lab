#include <iostream>
using namespace std;

class Node {
    private:
    Node *previous;
    public:
    Node *next;
    int data;
    Node (int d){
        data = d;
        next = nullptr;
        previous = nullptr;
        
    }
    Node (){
        next = previous = nullptr;
        
    }
friend class LinkedList;
friend class Queue;
};

//LinkedList Class
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
//Queue Class
class Queue{
    private: 
    Node *head;
    Node *tail;
    public:
    Queue(){
        head=tail=nullptr;
    }
    void enqueue(int value){
        Node *newNode = new Node(value);
        if (head==nullptr){
            head=tail = newNode;
            
        }
        else if(head!=nullptr){
            newNode ->previous = tail;
            tail->next = newNode;
            tail = tail->next;
        }
    }
    void dequeue(){
        if (head==nullptr){
            cout << "Queue is empty" << endl;
        }
        else {
            Node *tempPtr = head;
            head = head->next;
            delete tempPtr;
        }
    }
    int front(){
        if (head==nullptr){
            cout << "Queue is empty" << endl;
            return 9999;
        }
        else{
            return head->data;
        }
    }
    bool isEmpty(){
        if (head==nullptr){
            return true;
        }
        else{
            return false;
        }
    }

};
//Graph Class
class Graph { 
// No. of vertices 
int vertices; 

// Pointer to an 
// array containing 
// adjacency lists 
LinkedList* adj; 

public: 
// Constructor 
Graph(int v){
    this->vertices = v;
    adj = new LinkedList[v];
} 

// function to add 
// an edge to graph 
void addEdge(int v, int w){
    adj[v].addNodeAtTail(w);
    adj[w].addNodeAtTail(v);
}

// Returns count of nodes at 
// level l from given source. 
int BFS(int s, int l){
    bool *visited = new bool [vertices];
    int *level = new int[vertices];
//marks all nodes as not visited
    for (int i=0; i<vertices; i++){
        visited[i]=false;
        level[i]=0;
    }

Queue q;

visited[s]=true;
q.enqueue(s);
level[s]=0;

while (!q.isEmpty()){
    s=q.front();
    q.dequeue();


    for (auto i=adj[s].head; i!=nullptr; i=i->next){
        if (visited[i->data]==false){
            level[i->data]=level[s]+1;
            visited[i->data]=true;
            q.enqueue(i->data);
        }
    }
}
int count =0;
for (int i=0; i<vertices;i++){
    if (level[i]==l){
        count++;
    }
}   

return count;
}
}; 


int main() 
{ 
// Create a graph given 
// in the above diagram 
Graph g(6); 
g.addEdge(0, 1); 
g.addEdge(0, 2); 
g.addEdge(1, 3); 
g.addEdge(2, 4); 
g.addEdge(2, 5); 
//check nodes at level 2
int level = 2; 

cout << "Number of nodes at level " << level << " are: " <<g.BFS(0, level); 

return 0; 
} 