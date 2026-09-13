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

class Solution {
public:

    TreeNode* lastright(TreeNode* root)
    {
        while(root->right != NULL)
        {
            root = root->right;
        }

        return root;
    }

    TreeNode* helper(TreeNode* root)
    {
        if(root->left == NULL)
            return root->right;

        if(root->right == NULL)
            return root->left;

        TreeNode* ri = root->right;
        TreeNode* le = lastright(root->left);

        le->right = ri;

        return root->left;
    }

    TreeNode* deleteNode(TreeNode* root, int key)
    {
        if(root == NULL)
            return NULL;

        if(root->val == key)
            return helper(root);

        TreeNode* dummy = root;

        while(root != NULL)
        {
            if(key < root->val)
            {
                if(root->left != NULL && root->left->val == key)
                {
                    root->left = helper(root->left);
                    break;
                }
                else
                {
                    root = root->left;
                }
            }
            else
            {
                if(root->right != NULL && root->right->val == key)
                {
                    root->right = helper(root->right);
                    break;
                }
                else
                {
                    root = root->right;
                }
            }
        }

        return dummy;
    }
};

// Inorder traversal
void inorder(TreeNode* root)
{
    if(root == NULL)
        return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main()
{
    /*
            5
           / \
          3   8
         / \
        2   4
    */

    TreeNode* root = new TreeNode(5);

    root->left = new TreeNode(3);
    root->right = new TreeNode(8);

    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);

    cout << "Before deletion: ";
    inorder(root);

    int key = 3;

    Solution obj;
    root = obj.deleteNode(root, key);

    cout << "\nAfter deletion: ";
    inorder(root);

    return 0;
}