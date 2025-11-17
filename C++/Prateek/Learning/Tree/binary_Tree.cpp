#include<iostream>
#include<queue>

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

// LevelOrder build tree,
Node* levelOrder_buildTree() {
    int d;
    cin>>d;
    Node *root = new Node(d);
    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        Node* current = q.front();
        q.pop();
        int c1, c2;
        cin>>c1>>c2;
        if(c1 != -1){
            current->left = new Node(c1);
            q.push(current->left);
        }
        if(c2 != -1){
            current->right = new Node(c2);
            q.push(current->right);
        }
    }
    return root;
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

void printLevelOrder(Node *root) {
    queue<Node*> q;     // create a queue to the nodes
    q.push(root);       // push the first node
    q.push(NULL);       // push the NULL so that we can have '/n' after the every level
    while(!q.empty()) { // loop until queue is empty
        Node *temp = q.front(); // store the front of queue in the temp node
        if(temp != NULL) {  //  if temp is not null then proceed 
            q.pop();        //  remove the front of queue
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        } else {        // if temp is null then print '/n' and pop the front of queue
            cout<<endl;
            q.pop();
            if(!q.empty()) {
                q.push(NULL);   //  push the NULL only if queue is not empty
            }
        }
    }
    return;
}

int height(Node *root) {
    if(root == NULL) {
        return 0;
    }
    int h1 = height(root->left);
    int h2 = height(root->right);
    return max(h1, h2) + 1;
}

int main(int argc, char *argv[]) {
    Node *root = preOrder_buildTree();
    printPreorder(root);
    cout<<endl;
    printInorder(root);
    cout<<endl;
    printPostorder(root);
    cout<<endl;
    printLevelOrder(root);
    cout<<endl;
    cout<<"Height of a tree is : "<<height(root)<<endl;

    Node *root1 = preOrder_buildTree();
    printPreorder(root1);
    cout<<endl;
    printInorder(root1);
    cout<<endl;
    printPostorder(root1);
    cout<<endl;
    printLevelOrder(root1);
    cout<<endl;
    cout<<"Height of a tree1 is : "<<height(root)<<endl;
    cout<<endl;
}