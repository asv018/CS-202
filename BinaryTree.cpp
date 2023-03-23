// Using preorder
#include <iostream>
using namespace std;
// Using namespace std;
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

void preOrderTraversal(TreeNode* root) {
    if (root == NULL) return;

    cout << root->val << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

int main() {
    /*
        Constructing a binary tree
               1
             /   \
            2     3
           / \   / \
          4   5 6   7
    */

    TreeNode* root = new TreeNode(1);
    // add the nodes
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    cout << "Pre-order traversal: ";
    preOrderTraversal(root); // Output: 1 2 4 5 3 6 7

    return 0;
}
