/*Using queue template for this task as queue has already been implemented in task1*/

#include <iostream>
#include <queue>
using namespace std;

struct BinaryTreeNode{
int data;
BinaryTreeNode* left, *right;

};
//new tree node
BinaryTreeNode *newNode(int val){
    BinaryTreeNode *node = new BinaryTreeNode();
    node->data = val;
    node->left = node->right = nullptr;
    return node;
}

int oddEvenDifference(BinaryTreeNode *root){
    if (!root){
        return 0;
    }
    queue <BinaryTreeNode*> Q;
    //level order traversal to move between odd and even levels
    Q.push(root);
    int level = 0;
    int even = 0; //even sum
    int odd = 0; //odd sum
    //traversal
    while (!Q.empty()){
        int size = Q.size();
        level++;

        while (size>0){
            BinaryTreeNode *temp = Q.front();
            Q.pop();

            //if level is even
            if (level%2==0){
                even+=temp->data; //add value stored at node to even sum
            }
            //if level is odd
            else{
                odd+=temp->data;
            }
            //if node has children, push to queue for traversal
            if (temp->left){
                Q.push(temp->left);
            }
            if (temp->right){
                Q.push(temp->right);
            }
            size--;
        }
    }
    return (odd-even); //subtract even from odd and return result

}

int main()
{
// construct a tree
BinaryTreeNode* root = newNode(0);
root->left = newNode(1);
root->right = newNode(2);
root->left->left = newNode(3);
root->left->right = newNode(4);
root->left->right->left = newNode(8);
root->right->right = newNode(5);
root->right->right->right = newNode(7);
root->right->right->left = newNode(6);

int result = oddEvenDifference(root);
cout << "Difference: " << result << endl;
return 0;
}