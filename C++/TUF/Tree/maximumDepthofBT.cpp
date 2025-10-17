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
    return 0;
}