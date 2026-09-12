#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

// YOU WRITE THIS
int findMin(TreeNode* root) {
    while(root->left!=NULL)
    {
        root=root->left;
    }
    return root->val;
    
}

// YOU WRITE THIS
int findMax(TreeNode* root) {
    while(root->right!=NULL)
    {
        root=root->right;
    }
    return root->val;
    
}

int main() {

    // Create your BST here
    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(3);
    root->right = new TreeNode(10);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(6);

    cout << "Minimum: " << findMin(root) << endl;
    cout << "Maximum: " << findMax(root) << endl;

    return 0;
}