#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
public:
    int pathsum(TreeNode* root, int &maxi)
    {
        if(root == NULL)
            return 0;

        int leftsum = max(0, pathsum(root->left, maxi));
        int rightsum = max(0, pathsum(root->right, maxi));

        maxi = max(maxi, root->val + leftsum + rightsum);

        return root->val + max(leftsum, rightsum);
    }

    int maxPathSum(TreeNode* root)
    {
        if(root == NULL)
            return -1;

        if(root->left == NULL && root->right == NULL)
            return root->val;

        int maxi = INT_MIN;

        int n = pathsum(root, maxi);

        return maxi;
    }
};

int main()
{
    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution obj;

    cout << obj.maxPathSum(root) << endl;

    return 0;
}