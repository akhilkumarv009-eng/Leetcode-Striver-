#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if (root == NULL || p == NULL || q == NULL)
            return NULL;

        int val1 = max(p->val, q->val);
        int val2 = min(p->val, q->val);

        while (root != NULL) {

            if (root->val > val1 && root->val > val2)
                root = root->left;

            else if (root->val < val1 && root->val < val2)
                root = root->right;

            else
                return root;
        }

        return NULL;
    }
};