/*********** Inorder Traversal **********
 * Left->Root->Right
 * Inorder - Root is in between left and right
*/

#include<iostream>
#include<vector>
#include<stack>

class Node {
    public:
    int data;
    Node *left, *right;
    Node(int val):data(val),left(NULL),right(NULL){}
};

/************ Recursive Approach *******************/
void riot(Node* inorderRoot,std::vector<int> &temp) {
    if(inorderRoot == NULL) return;
    // we can see clearly that we follow same order like left->root->right here for manipulating data
    riot(inorderRoot->left,temp);       // Left
    temp.push_back(inorderRoot->data);  // Root
    riot(inorderRoot->right,temp);      // Right
}

std::vector<int> recursiveInorder(Node* tempRoot) {
    std::vector<int> arr;
    riot(tempRoot,arr); //  recursive inorder traversal
    return arr;
}
/****************************************************/

/************ Iterative Approach *******************/
std::vector<int> iterativeInorder(Node* inorderRoot) {
    std::stack<Node*> st;
    std::vector<int> inorderValue;
    while(true) {
        if(inorderRoot != NULL) {
            st.push(inorderRoot);
            inorderRoot = inorderRoot->left;
        } else {
            if(st.empty()){ 
                break;
            }
            inorderRoot = st.top();
            st.pop();
            inorderValue.push_back(inorderRoot->data);
            inorderRoot = inorderRoot->right;
        }
    }
    return inorderValue;
}
/***************************************************/

int main(int argc, char *argv[]) {
    std::vector<int> routput;
    std::vector<int> ioutput;
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    routput = recursiveInorder(root);

    std::cout<<"Inorder Recursive Traversal Value is : ";
    for(auto val : routput) {
        std::cout<<val<<" ";
    }
    std::cout<<std::endl;

    ioutput = iterativeInorder(root);
    std::cout<<"Inorder Iterative Traversal Value is : ";
    for(auto val : ioutput) {
        std::cout<<val<<" ";
    }
    std::cout<<std::endl;

    return 0;
}
/**************************************************/


