#include <iostream>
using namespace std;

class Node{
private:
Node *right;
Node *left;
int height;
int key;

public:
Node (int k){
right = nullptr;
left = nullptr;
height = 0;
key = k;
}
friend class AVLTree;
};

class AVLTree{
private:
Node *root;

//function for inOrder Traversal
void inorder(Node *temp){
    if (temp!=nullptr){
        inorder(temp->left);
        cout << temp->key << " ";
        inorder(temp->right);
    }
}
public:
AVLTree(){
    root = nullptr;
}
AVLTree(int x){
    root = new Node (x);
}
void ShowListinorder(){
    inorder(root);
}
Node *RRrotation (Node *z);
Node *LLrotation (Node *z);
Node *LRrotation(Node *K1);
Node *RLrotation(Node *K1);
Node *insert(int key, Node *temp);

void insertN(int x){
    root = insert(x,root);
}

//function to find height of a node
int height (Node *N){
    if (N==nullptr){
        return 0;
    }
    return N->height;
}
int max (int a, int b){
    if (a>b){
        return a;
    }
    else {
        return b;
    }
}

//function for finding height difference 
int diff(Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}
};

//right-right rotation function
Node* AVLTree:: RRrotation(Node *K2){
    Node *K1 = K2->right;
    K2->right = K1->left;
    K1->left = K2;
    K1->height = max(height(K1->left), height(K1->right))+1;
    K1->height = max(height(K1->left), height(K1->right))+1;
    return K1;
}

//left-left rotation function
Node *AVLTree::LLrotation(Node *K2){
    Node *K1 = K2->left;
    K2->left = K1->right;
    K1->right = K2;
    K2->height = max(height(K2->left), height(K2->right))+1;
    K1->height = max(height(K1->left), height(K1->right))+1;
    return K1;
}

//left-right rotation function
Node *AVLTree::LRrotation(Node *K1){
    K1->left = RRrotation (K1->left);
    return LLrotation(K1);
}

//right-left rotation function
Node *AVLTree::RLrotation(Node *K1){
    K1->right = LLrotation (K1->left);
    return RRrotation(K1);
}

//insert function
Node* AVLTree:: insert(int x, Node *temp){
    if (temp == nullptr){
        Node *newNode = new Node(x);
        temp = newNode;
    }
    else if (x<temp->key){
        temp->left = insert(x, temp->left);
        if (height(temp->left) - height(temp->right)==2){
            if (x<temp->left->key){
                temp=LLrotation(temp);
            }
            else {
                // temp = LRrotation(temp);
                temp->left = LLrotation(temp->left);
            return RRrotation(temp);
            }
        }
        
    }
    else if (x>temp->key){
        temp->right=insert(x, temp->right);
        if (height(temp->left) - height(temp->right)==2){
            if (x>temp->right->key){
            temp = RRrotation(temp);
            }
            else {
                // temp = RLrotation(temp);
                temp ->right = RRrotation(temp->right);
            return LLrotation(temp);
            }
        }
    }
        temp->height = max(height(temp->left), height(temp->right))+1;
        return temp;
}


int main(){

    AVLTree t;
    t.insertN(13);
    t.insertN(10);
    t.insertN(5);
    t.insertN(4);
    t.insertN(8);
    t.insertN(11);
    t.insertN(15);
    t.insertN(16);
    t.insertN(13);
    t.insertN(3);
    t.insertN(45);
    t.insertN(7);
    t.insertN(15);
    t.ShowListinorder();

}

