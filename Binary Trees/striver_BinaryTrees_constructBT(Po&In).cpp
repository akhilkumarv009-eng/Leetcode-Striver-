#include <iostream>
#include <vector>
#include <map>
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

    TreeNode* build(
        vector<int>& postorder,
        int ps,
        int pe,
        vector<int>& inorder,
        int is,
        int ie,
        map<int, int>& mp
    ) {

        // Base case
        if (ps > pe || is > ie)
            return NULL;

        // Root is the last element of postorder
        TreeNode* root = new TreeNode(postorder[pe]);

        // Find root position in inorder
        int element = mp[postorder[pe]];

        // Number of elements in left subtree
        int inroot = element - is;

        // Build left subtree
        root->left = build(
            postorder,
            ps,
            ps + inroot - 1,
            inorder,
            is,
            element - 1,
            mp
        );

        // Build right subtree
        root->right = build(
            postorder,
            ps + inroot,
            pe - 1,
            inorder,
            element + 1,
            ie,
            mp
        );

        return root;
    }

    TreeNode* buildTree(
        vector<int>& inorder,
        vector<int>& postorder
    ) {

        if (inorder.size() != postorder.size())
            return NULL;

        // Store inorder value -> index
        map<int, int> mp;

        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        // Construct tree
        TreeNode* root = build(
            postorder,
            0,
            postorder.size() - 1,
            inorder,
            0,
            inorder.size() - 1,
            mp
        );

        return root;
    }
};


// -------------------------
// Helper Functions
// -------------------------

void printPreorder(TreeNode* root) {

    if (root == NULL)
        return;

    cout << root->val << " ";

    printPreorder(root->left);
    printPreorder(root->right);
}


// -------------------------
// Main Function
// -------------------------

int main() {

    vector<int> inorder = {9, 3, 15, 20, 7};

    vector<int> postorder = {9, 15, 7, 20, 3};

    Solution obj;

    TreeNode* root = obj.buildTree(inorder, postorder);

    cout << "Preorder of constructed tree: ";

    printPreorder(root);

    cout << endl;

    return 0;
}