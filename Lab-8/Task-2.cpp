#include <iostream>
#include <algorithm>
using namespace std;

class Node{
    private:
    Node *left;
    Node *right;
    int data;
    int h;
    public:
    Node(int d){
        left = nullptr;
        right = nullptr;
        data = d;
    }
    friend class BinarySearchTree;
};

class BinarySearchTree{
private: 
void displayInOrder(Node *nodePtr);
void displayPreOrder(Node *nodePtr);
void displayPostOrder(Node *nodePtr);
void deleteNode(int value, Node *&nodePtr);
void deletion (Node *&nodePtr);
public:
Node *root;
BinarySearchTree(){
    root = nullptr;
}
void insertNode(int value){
    Node *newNode = new Node(value);
    Node *tempNode = root;
    if (tempNode==nullptr){
        root = newNode;
    }
    else {
        while (tempNode!=nullptr){
            if (value<tempNode->data){
                if (tempNode->left){
                tempNode=tempNode->left;
                }
                else {
                    tempNode->left=newNode;
                    break;
                }
            }
            else if (value>tempNode->data){
                if (tempNode->right){
                    tempNode=tempNode->right;
                    }
                    else {
                        tempNode->right = newNode;
                        break;
                    }
            }
            else {
                cout << "Value already exists";
            }
        }
        
    }
}
void showListInOrder(){
        displayInOrder(this->root);
}
void showListPreOrder(){
    displayPreOrder(this->root);
}
void showListPostOrder(){
    displayPostOrder(this->root);
}
bool searchNode (int value){
    Node *temp = root;
    if (!root){
        return false;
    }
    else {
        while (temp){
            if (temp->data==value){
                return true;
            }
            else if (value<temp->data){
                temp=temp->left;
            }
            else if (value>temp->data){
                temp=temp->right;
            }
        } 
    }   
    return false;
}
void removeNode(int num){
deleteNode (num, root);
}
bool checkLeaves(Node *root, int *previous, int current){
    if (root==nullptr){
        return true;
    }
    else if(root->left==nullptr && root->right==nullptr){
        if (*previous==0){
            *previous = current;
            return true;
        }
        return *previous ==current;
    }
    return checkLeaves(root->left, previous, current+1) && checkLeaves(root->right, previous, current+1); 
}
void checkLevel(){
    int previous = 0;
    int current = 0;
    if (checkLeaves(root ,&previous, current)==1)
    {
        cout << "True";
    }
    else {
        cout << "False";
    }
}




};
void BinarySearchTree::displayInOrder(Node *ptr){
    if (ptr){
        displayInOrder(ptr->left);
        cout << ptr->data << " ";
        displayInOrder(ptr->right);
    }
}
void BinarySearchTree::displayPreOrder(Node *ptr){
    if (ptr){
        cout << ptr->data << " ";
        displayPreOrder(ptr->left);
        displayPreOrder(ptr->right);
    }
}
void BinarySearchTree::displayPostOrder(Node *ptr){
    if (ptr){
        displayPostOrder(ptr->left);
        displayPostOrder(ptr->right);
        cout << ptr->data << " ";
        }
}
void BinarySearchTree::deleteNode(int value, Node *&nodePtr){
    if (value < nodePtr->data){
        deleteNode(value, nodePtr->left);
    }
    else if (value > nodePtr->data){
        deleteNode(value, nodePtr->right);
    }
    else {
        deletion(nodePtr);
    }
}
void BinarySearchTree::deletion(Node *&nodePtr){
    Node *tempPtr;
    if (nodePtr==nullptr){
        cout << "Cannot delete empty Node" << endl;
    }
    else if (nodePtr->right==nullptr){
        tempPtr = nodePtr;
        nodePtr= nodePtr->left;
        delete tempPtr;
    }
    else if (nodePtr->left==nullptr){
        tempPtr = nodePtr;
        nodePtr= nodePtr->right;
        delete tempPtr;
    }
    else {
        tempPtr = nodePtr->right;
        while (tempPtr->left){
            tempPtr=tempPtr->left;
        }
        tempPtr->left=nodePtr->left;
        tempPtr=nodePtr;
        nodePtr=nodePtr->right;
        delete tempPtr;
    }
}
int main(){
    BinarySearchTree tree;
    tree.insertNode(10);
    tree.insertNode(5);
    tree.insertNode(2);
    tree.insertNode(11);
    tree.showListInOrder();
    cout << endl;
    tree.showListPreOrder();
    cout << endl;
    tree.showListPostOrder();
    cout << endl;
    tree.checkLevel();
    
}
