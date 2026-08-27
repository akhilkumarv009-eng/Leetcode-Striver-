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
    bool sym(TreeNode* p, TreeNode* q)
    {
        if(p == NULL && q == NULL)
            return true;

        if(p == NULL || q == NULL)
            return false;

        if(p->val == q->val)
        {
            return sym(p->right, q->left) &&
                   sym(p->left, q->right);
        }
        else
        {
            return false;
        }
    }

    bool isSymmetric(TreeNode* root)
    {
        if(root == NULL)
            return true;

        bool x;

        x = sym(root->left, root->right);

        return x;
    }
};

int main()
{
    /*
              1
             / \
            2   2
           / \ / \
          3  4 4  3
    */

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(2);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);

    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    Solution obj;

    if(obj.isSymmetric(root))
        cout << "Tree is Symmetric" << endl;
    else
        cout << "Tree is Not Symmetric" << endl;

    return 0;
}