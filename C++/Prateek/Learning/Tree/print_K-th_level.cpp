/*  K-th Level      :   Given a binary tree with N nodes. Your task is to print its Kth level.
    Input Format    :   In the function a pointer to the root node of the binary tree is passed.
    Output Format   :   Return a vector containing nodes at Kth level
    Input:       
          60             --- Level 0
         /  \
       50    30          --- Level 1
      /  \   /
    80   10 40           --- Level 2
 
    K = 1
    Output: 30 50
 
    Input:
           50            --- Level 0
          /  \
        60    70         --- Level 1
       /  \   / \
     90   40 40  20      --- Level 2
    K = 2
    Output: 20 40 90
*/


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Input : 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
// -1 means NULL just to form a tree we are using this reference

struct Node {
    int key;
    Node* left, *right;
    Node(int d):key(d),left(NULL),right(NULL){}
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

void printLevelOrder(Node *root) {
    queue<Node*> q;     // create a queue to the nodes
    q.push(root);       // push the first node
    q.push(NULL);       // push the NULL so that we can have '/n' after the every level
    while(!q.empty()) { // loop until queue is empty
        Node *temp = q.front(); // store the front of queue in the temp node
        if(temp != NULL) {  //  if temp is not null then proceed 
            q.pop();        //  remove the front of queue
            cout<<temp->key<<" ";
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

vector<int> printKthLevel(Node* root, int k){
    // your code goes here
    vector<int> out;
    if(root == NULL) return out;
   
    queue<Node*> q;
    q.push(root);
    int level = 0;
   
    while(!q.empty()) {
        int size = q.size();
       
        if(level == k) {
            for(int i = 0; i < size; ++i) {
                Node *temp = q.front();
                q.pop();
                out.push_back(temp->key);
            }
            return out;
        }
       
        for(int i = 0; i < size; ++i) {
            Node *temp = q.front();
            q.pop();
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        level++;
    }
    return out;
}

int main(int argc, char**argv) {
    Node *root = preOrder_buildTree();
    printLevelOrder(root);
    cout<<endl;
    vector<int> out = printKthLevel(root, 2);
    for(int val : out){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}
