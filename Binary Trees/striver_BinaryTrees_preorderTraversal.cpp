#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x)
    {
        val = x;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    void preorder(TreeNode* root, vector<int> &ans)
    {
        if (root == NULL)
            return;

        ans.push_back(root->val);

        preorder(root->left, ans);
        preorder(root->right, ans);
    }

    vector<int> preorderTraversal(TreeNode* root)
    {
        vector<int> ans;
        preorder(root, ans);
        return ans;
    }
};

int main()
{
    // Creating the binary tree
    //
    //        5
    //       / \
    //      3   4
    //
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(4);

    Solution obj;

    vector<int> result = obj.preorderTraversal(root);

    // Print preorder traversal
    for (int x : result)
    {
        cout << x << " ";
    }

    return 0;
}