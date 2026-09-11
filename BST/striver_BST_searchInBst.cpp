#include <iostream>
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
    TreeNode* searchBST(TreeNode* root, int val) {
        while (root != NULL && root->val != val) {
            root = val < root->val ? root->left : root->right;
        }
        return root;
    }
};

int main() {
    // Creating BST
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    int val;
    cout << "Enter value to search: ";
    cin >> val;

    Solution obj;
    TreeNode* result = obj.searchBST(root, val);

    if (result != NULL)
        cout << "Value found: " << result->val << endl;
    else
        cout << "Value not found" << endl;

    return 0;
}