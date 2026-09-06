#include <iostream>
#include <stack>

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

    void flatten(TreeNode* root) {

        if (root == NULL)
            return;

        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty()) {

            TreeNode* cur = st.top();
            st.pop();

            // Push right first
            if (cur->right)
                st.push(cur->right);

            // Push left second
            if (cur->left)
                st.push(cur->left);

            // Top is the next node in preorder
            if (!st.empty())
                cur->right = st.top();

            // Flattened tree should not have left children
            cur->left = NULL;
        }
    }
};

int main() {

    /*
             1
            / \
           2   5
          / \   \
         3   4   6
    */

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(5);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);

    root->right->right = new TreeNode(6);

    Solution obj;

    obj.flatten(root);

    // Print flattened tree
    cout << "Flattened tree: ";

    TreeNode* cur = root;

    while (cur != NULL) {
        cout << cur->val << " ";
        cur = cur->right;
    }

    cout << endl;

    return 0;
}