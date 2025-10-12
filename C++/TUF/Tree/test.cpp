/*********** Inorder Traversal ***********/

*/#include<iostream>
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
    riot(inorderRoot->left,temp);
    temp.push_back(inorderRoot->data);
    riot(inorderRoot->right,temp);
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
    Node *node = inorderRoot;
    std::vector<int> inorderValue;
    while(true) {
        if(node != NULL) {
            st.push(node);
            node = node->left;
        } else {
            if(st.empty()){ 
                break;
            }
            node = st.top();
            st.pop();
            inorderValue.push_back(node->data);
            node = node->right;
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
/*********** Preorder Traversal ***********/
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
    if(preorderRoot == NULL) return;
    temp.push_back(preorderRoot->data);
    preorderTraverse(preorderRoot->left,temp);    
    preorderTraverse(preorderRoot->right,temp);
}

std::vector<int> recursivePreorder(Node* tempRoot) {
    std::vector<int> arr;
    preorderTraverse(tempRoot,arr);
    return arr;
}
/**************************************************/

/************ Iterative Approach *******************/
std::vector<int> iterativePreorder(Node* inorderRoot) {
    std::stack<Node*> st;
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
    std::cout<<"Preorder Recursive Traversal Value is : ";
    for(auto val : ioutput) {
        std::cout<<val<<" ";
    }
    std::cout<<std::endl;

    return 0;
}
/****************************************/
/************* Postorder Traversal ****************/
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
void postOrderTraverse(Node* postOrderRoot,std::vector<int> &temp) {
    if(postOrderRoot == NULL) return;
    postOrderTraverse(postOrderRoot->right,temp);
    postOrderTraverse(postOrderRoot->left,temp);
    temp.push_back(postOrderRoot->data);
}

std::vector<int> recursivepostOrder(Node* tempRoot) {
    std::vector<int> arr;
    postOrderTraverse(tempRoot,arr);
    return arr;
}
/**************************************************/

/************ Iterative Approach *******************/
std::vector<int> iterativePostorder(Node* inorderRoot) {
    std::stack<Node*> st;
    std::vector<int> postorderValue;
    Node *node = inorderRoot;
    while(true) {
        if(node != NULL) {
            st.push(node);
            node = node->right;
        } else {
            if(st.empty()) {
                break;
            }
            node = st.top();
            st.pop();
            postorderValue.push_back(node->data);
            node = node->left;
        }
    }
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
