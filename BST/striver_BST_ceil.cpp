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
int findCeil(TreeNode* root, int x) {
    int ans = 0;

    while(root!=NULL)
    {
        if(root->val >= x)
        {
            ans = root->val;
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return ans;

}


int main() {

    // Create BST
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(13);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(6);
    root->right->right = new TreeNode(14);
    root->right->left = new TreeNode(11);
    root->left->left->left=new TreeNode(2);
    root->left->left->right=new TreeNode(4);
    root->left->right->right=new TreeNode(9);
    

    int x = 11;

    cout << "Ceil: " << findCeil(root, x) << endl;

    return 0;
}