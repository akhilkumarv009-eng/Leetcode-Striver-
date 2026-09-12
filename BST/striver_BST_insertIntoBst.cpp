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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* node = new TreeNode(val);

        if (root == NULL)
            return node;

        TreeNode* ans;
        TreeNode* cur = root;

        while (cur != NULL) {
            ans = cur;

            if (cur->val < val) {
                cur = cur->right;
            }
            else {
                cur = cur->left;
            }
        }

        if (ans->val > val) {
            ans->left = node;
        }
        else {
            ans->right = node;
        }

        return root;
    }
};

int main() {

    // Create BST
    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(3);
    root->right = new TreeNode(10);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(6);

    Solution obj;

    int val = 5;

    root = obj.insertIntoBST(root, val);

    cout << "Inserted " << val << " into BST." << endl;

    return 0;
}