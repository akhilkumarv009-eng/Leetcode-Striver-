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

// Find inorder successor of a given key
TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    if(root==NULL)return NULL;
   TreeNode* suc =NULL;
   while(root!=NULL)
   {
    if(root->val > p->val)
    {
        suc = root;
        root = root->left;
    }
    else if(root->val <= p->val)
    {
        root = root->right;
    }
   }
   return suc;
}

int main() {

    //          20
    //         /  \
    //       10    30
    //      /  \   / \
    //     5   15 25 35

    TreeNode* root = new TreeNode(20);

    root->left = new TreeNode(10);
    root->right = new TreeNode(30);

    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(15);

    root->right->left = new TreeNode(25);
    root->right->right = new TreeNode(35);

    // Find successor of 15
    TreeNode* p = root->left->right;

    TreeNode* ans = inorderSuccessor(root, p);

    if (ans != NULL)
        cout << "Inorder Successor of " << p->val
             << " is " << ans->val << endl;
    else
        cout << "Inorder Successor does not exist" << endl;

    return 0;
}