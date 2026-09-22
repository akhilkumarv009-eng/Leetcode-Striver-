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
    bool check(TreeNode* root, long long minn, long long maxx) {
        if (root == NULL)
            return true;

        if (root->val > minn && root->val < maxx) {
            return check(root->left, minn, root->val) &&
                   check(root->right, root->val, maxx);
        }
        else {
            return false;
        }
    }

    bool isValidBST(TreeNode* root) {
        if (root == NULL)
            return true;

        return check(root, LLONG_MIN, LLONG_MAX);
    }
};

int main() {

    // Creating this tree:
    //
    //        10
    //       /  \
    //      5    15
    //          /  \
    //         12   20

    TreeNode* root = new TreeNode(10);

    root->left = new TreeNode(5);
    root->right = new TreeNode(15);

    root->right->left = new TreeNode(12);
    root->right->right = new TreeNode(20);

    Solution obj;

    if (obj.isValidBST(root))
        cout << "Valid BST" << endl;
    else
        cout << "Not a Valid BST" << endl;

    return 0;
}