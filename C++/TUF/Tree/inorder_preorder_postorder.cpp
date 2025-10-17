#include <bits/stdc++.h>
using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};


class Solution{
    private:
    void preorder(TreeNode *root, vector<int> &value) {
        if(root == nullptr) {
            return;
        }
        value.push_back(root->data);
        preorder(root->left, value);
        preorder(root->right, value);
    }
    void inorder(TreeNode *root, vector<int> &value) {
        if(root == nullptr) {
            return;
        }
        inorder(root->left, value);
        value.push_back(root->data);
        inorder(root->right, value);
    }
    void postorder(TreeNode *root, vector<int> &value) {
        if(root == nullptr) {
            return;
        }
        postorder(root->left, value);
        postorder(root->right, value);
        value.push_back(root->data);
    }
	public:
		vector<vector<int> > treeTraversal(TreeNode* root){
			//your code goes here
            vector<vector<int>> output(3);
            inorder(root, output[0]);
            preorder(root, output[1]);
            postorder(root, output[2]);
            return output;
		}
};


/* Raj Solution
class Solution {
public:
    vector<vector<int>> treeTraversal(TreeNode* root) {
        // Vectors to store the traversals
        vector<int> pre, in, post;

        // If the tree is empty, return empty traversals
        if (root == nullptr) return { in, pre, post };

        // Stack to maintain nodes and their traversal state
        stack<pair<TreeNode*, int>> st;

        // Start with the root node and state 1 (preorder)
        st.push({ root, 1 });

        while (!st.empty()) {
            // Get the top element from the stack
            auto [node, state] = st.top();
            st.pop();

            // Process the node based on its state
            if (state == 1) {
                // Preorder: Add node data
                pre.push_back(node->data);
                // Change state to 2 (inorder) for this node
                st.push({ node, 2 });

                // Push left child onto the stack for processing
                if (node->left != nullptr) {
                    st.push({ node->left, 1 });
                }
            } else if (state == 2) {
                // Inorder: Add node data
                in.push_back(node->data);
                // Change state to 3 (postorder) for this node
                st.push({ node, 3 });

                // Push right child onto the stack for processing
                if (node->right != nullptr) {
                    st.push({ node->right, 1 });
                }
            } else {
                // Postorder: Add node data
                post.push_back(node->data);
            }
        }

        // Return the traversals as a 2D vector
        return { in, pre, post};
    }
};
*/

// Main function to test the tree traversal
int main() {
    // Creating a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution sol;
    vector<vector<int>> traversals = sol.treeTraversal(root);

    // Print Preorder traversal
    cout << "Preorder traversal: ";
    for (int val : traversals[1]) cout << val << " ";
    cout << endl;

    // Print Inorder traversal
    cout << "Inorder traversal: ";
    for (int val : traversals[0]) cout << val << " ";
    cout << endl;

    // Print Postorder traversal
    cout << "Postorder traversal: ";
    for (int val : traversals[2]) cout << val << " ";
    cout << endl;

    return 0;
}
