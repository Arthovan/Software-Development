#include<iostream>

using namespace std;
// Input : 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
// -1 means NULL just to form a tree we are using this reference

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int d){
        data = d;
        left=right=nullptr;
    }
};

// Preorder build tree, Root->Left->Right
Node* buildTree() {
    int d;
    cin>>d;
    if(d == -1) {
        return nullptr;
    }

    Node *n = new Node(d);
    n->left = buildTree();
    n->right = buildTree();
    return n;
}

void printPreorder(Node *root) {
    if(root == nullptr) {
        return;
    }
    cout<<root->data<<" ";
    printPreorder(root->left);
    printPreorder(root->right);
}

void printInorder(Node *root) {
    if(root == nullptr) {
        return;
    }
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}

void printPostorder(Node *root) {
    if(root == nullptr) {
        return;
    }
    printPostorder(root->left);
    printPostorder(root->right);
    cout<<root->data<<" "; 
}

int main(int argc, char *argv[]) {
    Node *root = buildTree();
    printPreorder(root);
    cout<<endl;
    printInorder(root);
    cout<<endl;
    printPostorder(root);
    cout<<endl;
}