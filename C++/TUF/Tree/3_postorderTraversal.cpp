/************* Postorder Traversal ***************
 * Left->Right->Root
 * Postorder - Left and right then Root at the end
*/
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

class Node {
    public:
    int data;
    Node *left, *right;
    Node(int val):data(val),left(NULL),right(NULL){}
};

/************ Recursive Approach *******************/
void postOrderTraverse(Node* postOrderRoot,std::vector<int> &temp) {
    // we can see clearly that we follow same order like left->right->root here for manipulating data
    if(postOrderRoot == NULL) return;
    postOrderTraverse(postOrderRoot->left,temp);    //  Left
    postOrderTraverse(postOrderRoot->right,temp);   //  Right
    temp.push_back(postOrderRoot->data);            //  Root
}

std::vector<int> recursivepostOrder(Node* tempRoot) {
    std::vector<int> arr;
    postOrderTraverse(tempRoot,arr);
    return arr;
}
/**************************************************/

/************ Iterative Approach *******************/
std::vector<int> iterativePostorder(Node* postorderRoot) {
    std::vector<int> postorderValue;
    std::stack<Node*> st;
    st.push(postorderRoot);
    
    while(!st.empty()) {
        postorderRoot = st.top();
        st.pop();
        postorderValue.push_back(postorderRoot->data);
        if(postorderRoot->left != NULL) {
            st.push(postorderRoot->left);
        }
        if(postorderRoot->right != NULL) {
            st.push(postorderRoot->right);
        }
    }
    reverse(postorderValue.begin(), postorderValue.end());
    return postorderValue;
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

    routput = recursivepostOrder(root);
    std::cout<<"Postorder Recursive Traversal Value is : ";
    for(auto val : routput) {
        std::cout<<val<<" ";
    }
    std::cout<<std::endl;

    ioutput = iterativePostorder(root);
    std::cout<<"Postorder Iterative Traversal Value is : ";
    for(auto val : ioutput) {
        std::cout<<val<<" ";
    }
    std::cout<<std::endl;

    return 0;
}
/********************************************/