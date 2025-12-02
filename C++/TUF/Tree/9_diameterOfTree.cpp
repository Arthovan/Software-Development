#include<iostream>
#include<vector>
#include<queue>

class Node {
public:
    int data;
    Node *left, *right;
    Node(int v):data(v), left(NULL), right(NULL) {}
};

// This buildTree() is a preorder tree as it follows root->left->right
Node* buildTree() {
    int data;
    std::cin>>data;
    if(data == -1) {
        return NULL;
    }
    Node *node = new Node(data);
    node->left = buildTree();
    node->right = buildTree();
    return node;
}

void printTree(Node *root) {
    if(root == NULL) {
        return;
    }
    std::cout<<root->data<<" ";
    printTree(root->left);
    printTree(root->right);
}

std::vector<std::vector<int>> levelorderTraverse(Node *root) {
    std::vector<std::vector<int>> output;
    if(root == NULL) {
        return output;
    }
    std::queue<Node *> q;
    q.push(root);
    while(!q.empty()) {
        int size = q.size();
        std::vector<int> level;
        for(int i = 0; i < size; i++) {
            Node *node = q.front();
            q.pop();
            if(node->left != NULL) q.push(node->left);
            if(node->right != NULL) q.push(node->right);
            level.push_back(node->data);
        }
        output.push_back(level);
    }
    return output;
}

int maxDepth(Node* root) {
    //your code goes here
    if(root == nullptr) {
        return 0;
    }
    /*********** Iterative Approach ***************/
    std::queue<Node *> q;
    q.push(root);
    int level = 0;
    while(!q.empty()) {
        int size = q.size();
        for(int i = 0; i < size; ++i) {
            Node *node = q.front();
            q.pop();
            if(node->left != nullptr) q.push(node->left);
            if(node->right != nullptr) q.push(node->right);
        }
        level++;
    }
    return level; 
    //////////////////////////////////////

    /********** Recursive Approach *****************/
    int lh = maxDepth(root->left);
    int rh = maxDepth(root->right);
    return 1 + std::max(lh,rh);
    ////////////////////////////////////
}

int dfsHeight(Node* root) {
    if(root == NULL) return 0;

    int lh = dfsHeight(root->left);
    if(lh == -1) return -1;
    int rh = dfsHeight(root->right);
    if(lh == -1) return -1;

    if(abs(lh - rh) > 1) return -1;
    return 1 + std::max(lh, rh);
}

bool isBalancedTree(Node* root) {
    return dfsHeight(root) != -1;
}

int height(Node* node, int &diameter){
    if (node == nullptr) {
        return -1;
    }
    int lh = height(node->left, diameter);
    int rh = height(node->right, diameter);
    diameter = max(diameter, lh + rh);
    return 1 + max(lh, rh);
}
int diameterOfBinarytree(Node* root) {
    int diameter = 0;
    height(root, diameter);
    return diameter
}

int main(int argc, char *argv[]) {
    Node *root = buildTree();   // input : 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
    printTree(root);
    std::cout<<std::endl;
    std::vector<std::vector<int>> traverse = levelorderTraverse(root);
    for(auto val : traverse){
        for(int temp : val) {
            std::cout<<temp<<" ";
        }
        std::cout<<std::endl;
    }
    std::cout<<"Maximum Depth is : "<<maxDepth(root)<<std::endl;
    if(isBalancedTree(root)) {
        std::cout<<"Balanced Binary Tree"<<std::endl;
    } else {
        std::cout<<"Not a Balanced Binary Tree"<<std::endl;
    }
    std::cout<<"Diameter of Tree : "<<diameterOfBinarytree(root)<<std::endl;
    return 0;
}