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
    TreeNode* check(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(root == NULL)
            return NULL;

        if(root == p || root == q)
            return root;

        TreeNode* left = check(root->left, p, q);
        TreeNode* right = check(root->right, p, q);

        if(left == NULL)
            return right;

        if(right == NULL)
            return left;

        return root;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        return check(root, p, q);
    }
};

int main()
{
    /*
              3
             / \
            5   1
           / \ / \
          6  2 0  8
            / \
           7   4
    */

    TreeNode* root = new TreeNode(3);

    root->left = new TreeNode(5);
    root->right = new TreeNode(1);

    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);

    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);

    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    // p = 5, q = 1
    TreeNode* p = root->left;
    TreeNode* q = root->right;

    Solution obj;

    TreeNode* ans = obj.lowestCommonAncestor(root, p, q);

    cout << "Lowest Common Ancestor = " << ans->val << endl;

    return 0;
}