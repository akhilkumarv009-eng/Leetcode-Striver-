#include <iostream>
#include <queue>
using namespace std;

/**
 * Definition for a binary tree node.
 */
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
    int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0;

        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});

        int m = 1;

        while(!q.empty())
        {
            auto it = q.front();
            q.pop();

            m = max(m, it.second);

            if(it.first->left != NULL)
            {
                q.push({it.first->left, it.second + 1});
            }

            if(it.first->right != NULL)
            {
                q.push({it.first->right, it.second + 1});
            }
        }

        return m;
    }
};