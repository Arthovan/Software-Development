#include<iostream>
#include<queue>

using namespace std;

class Node{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) : data(val), left(NULL), right(NULL){}
};

Node* preOrderBuildTree() {
    int d;
    cin>>d;

    if(d == -1){
        return NULL;
    }
    Node* node = new Node(d);
    node->left = preOrderBuildTree();
    node->right = preOrderBuildTree();
    return node;
}

void printPreOrder(Node* root) {
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}

void printInOrder(Node* root) {
    if(root == NULL){
        return;
    }
    printInOrder(root->left);
    cout<<root->data<<" ";
    printInOrder(root->right);
}

void printPostOrder(Node* root) {
    if(root == NULL){
        return;
    }
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout<<root->data<<" ";
}

void printLevelOrder(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()) {
        Node *temp = q.front();
        if(temp != NULL) {
            q.pop();
            cout<<temp->data<<" ";
            if(temp->left) {
                q.push(temp->left);
            }
            if(temp->right) {
                q.push(temp->right);
            }
        } else {
            cout<<endl;
            q.pop();
            if(!q.empty()) {
                q.push(NULL);
            }
        }
    }
    return;
}

int main(int argc, char*argv[]){
    Node* root = preOrderBuildTree();
    printPreOrder(root);
    cout<<endl;
    printInOrder(root);
    cout<<endl;
    printPostOrder(root);
    cout<<endl;
    printLevelOrder(root);
    cout<<endl;
    return 0;
}