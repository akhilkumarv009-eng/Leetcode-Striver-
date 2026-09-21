#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

class Solution {
public:
    int inorder(TreeNode* root, int k, int& cnt)
    {
        if (root == NULL)
            return -1;

        // Go left
        int leftans = inorder(root->left, k, cnt);

        if (leftans != -1)
            return leftans;

        // Visit current node
        cnt++;

        if (cnt == k)
            return root->val;

        // Go right
        return inorder(root->right, k, cnt);
    }

    int kthSmallest(TreeNode* root, int k)
    {
        int cnt = 0;
        return inorder(root, k, cnt);
    }
};

int main()
{
    /*
             5
            / \
           3   6
          / \
         2   4
        /
       1

       Inorder: 1 2 3 4 5 6
    */

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);

    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);

    root->left->left->left = new TreeNode(1);

    int k = 3;

    Solution obj;

    cout << "The " << k << "th smallest element is: "
         << obj.kthSmallest(root, k) << endl;

    return 0;
}