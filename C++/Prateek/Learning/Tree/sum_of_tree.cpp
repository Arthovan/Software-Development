/*  Sum of Nodes    :   Given a binary tree with N nodes. Your task is to return the sum of all N nodes.
    Input Format    :   In the function a pointer to the root node of the binary tree is passed.
    Output Format   :   Return a integer representing sum of all nodes
    Sample Input    :        2             --- Level 0
                            /  \
                           7    5          --- Level 1
                          /  \  /
                         8    1 4          --- Level 2

 Sample Output      :   27
 */

#include <bits/stdc++.h>
using namespace std;
 
struct Node {
    int key;
    Node* left, *right;
    Node(int d):key(d), left(NULL), right(NULL){}
};

// Preorder build tree, Root->Left->Right
Node* preOrder_buildTree() {
    int d;
    cin>>d;
    if(d == -1) {
        return nullptr;
    }

    Node *n = new Node(d);
    n->left = preOrder_buildTree();
    n->right = preOrder_buildTree();
    return n;
}

void printPreorder(Node *root) {
    if(root == nullptr) {
        return;
    }
    cout<<root->key<<" ";
    printPreorder(root->left);
    printPreorder(root->right);
}

int sumBT(Node* root)
{
    // Code here
    if(root == NULL) return 0;
    return root->key + sumBT(root->left) + sumBT(root->right);
}

int main(int argc, char *argv[]) {
    Node *root = preOrder_buildTree();
    printPreorder(root);
    cout<<endl;
    cout<<"Sum of tree : "<<sumBT(root);
    cout<<endl;
}