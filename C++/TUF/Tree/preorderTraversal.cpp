/*********** Preorder Traversal **********
 * Root->Left->Right
 * Preorder - Root is first then left and right follows
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
void preorderTraverse(Node* preorderRoot,std::vector<int> &temp) {
    // we can see clearly that we follow same order like root->left->right here for manipulating data
    if(preorderRoot == NULL) return;
    temp.push_back(preorderRoot->data);         //  Root
    preorderTraverse(preorderRoot->left,temp);  //  Left  
    preorderTraverse(preorderRoot->right,temp); //  Right
}

std::vector<int> recursivePreorder(Node* tempRoot) {
    std::vector<int> arr;
    preorderTraverse(tempRoot,arr);
    return arr;
}
/**************************************************/

/************ Iterative Approach *******************/
std::vector<int> iterativePreorder(Node* preorderRoot) {
    // Raj Method
    std::vector<int> preOrderValue;
    if(preorderRoot == NULL) {
        return preOrderValue;
    } 
    std::stack<Node*> st;
    st.push(preorderRoot);
    
    while(!st.empty()) {
        preorderRoot = st.top();
        st.pop();
        preOrderValue.push_back(preorderRoot->data);
        if(preorderRoot->right != NULL) {
            st.push(preorderRoot->right);
        }
            
        if(preorderRoot->left != NULL) {
            st.push(preorderRoot->left);
        }
    }
    return preOrderValue;
    
/*  std::stack<Node*> st;
    std::vector<int> preorderValue;
    Node *node = inorderRoot;
    while(true) {
        if(node != NULL) {
            preorderValue.push_back(node->data);
            st.push(node);
            node = node->left;          
        } else {
            if(st.empty()) {
                break;
            }
            node = st.top();
            st.pop();
            node = node->right;
        }
    }
    return preorderValue;
*/
 }
/***************************************************/

int main(int argc, char *argv[]) {
    std::vector<int> routput, ioutput;
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    routput = recursivePreorder(root);
    std::cout<<"Preorder Recursive Traversal Value is : ";
    for(auto val : routput) {
        std::cout<<val<<" ";
    }
    std::cout<<std::endl;

    ioutput = iterativePreorder(root);
    std::cout<<"Preorder Iterative Traversal Value is : ";
    for(auto val : ioutput) {
        std::cout<<val<<" ";
    }
    std::cout<<std::endl;

    return 0;
}
/****************************************/