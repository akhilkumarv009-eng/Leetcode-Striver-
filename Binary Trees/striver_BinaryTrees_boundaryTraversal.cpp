#include <iostream>
#include <vector>
#include <stack>
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

    // Check if node is a leaf
    bool isleaf(TreeNode* root) {
        return root != nullptr &&
               root->left == nullptr &&
               root->right == nullptr;
    }

    // Add left boundary (excluding leaf nodes)
    void addLeftBoundary(TreeNode* root, vector<int>& ans) {
        if(root==NULL)return;

        while(root!=NULL)
        {
            if(!isleaf(root))
            {
                ans.push_back(root->val);
            }
            if(root->left!=NULL)
            {
                root=root->left;
            }
            else
            {
                root=root->right;
            }
            }
        }

    // Add all leaf nodes
    void addLeaves(TreeNode* root, vector<int>& ans) {
        if(isleaf(root))
        ans.push_back(root->val);
        else
        {
            if(root->left!=NULL)
            {
                addLeaves(root->left,ans);
            }
            if(root->right!=NULL)
            {
                addLeaves(root->right,ans);
            }
            
        }
    }

    // Add right boundary (excluding leaf nodes)
    // Added in reverse order
    void addRightBoundary(TreeNode* root, vector<int>& ans) {
        stack<TreeNode*> st;
        if(root==NULL)return;

        while(root!=NULL)
        {
            if(!isleaf(root))
            {
                st.push(root);
            }
            if(root->right!=NULL)
            {
                root=root->right;
            }
            else
            {
                root=root->left;
            }

        }
        while(!st.empty())
        {
            ans.push_back(st.top()->val);
            st.pop();
        }
    }

    vector<int> boundary(TreeNode* root) {

        vector<int> ans;

        if (root == nullptr)
            return ans;

        // Root is included unless it is handled as a leaf
        if (!isleaf(root))
            ans.push_back(root->val);

        // Left Boundary
        addLeftBoundary(root->left, ans);

        // Leaf Nodes
        addLeaves(root, ans);

        // Right Boundary
        addRightBoundary(root->right, ans);

        return ans;
    }
};

int main() {

    /*
              1
             / \
            2   3
           / \   \
          4   5   6
             / \
            7   8

        Expected Boundary:
        1 2 4 7 8 6 3
    */

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->right = new TreeNode(6);

    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(8);

    // Create object
    Solution obj;

    // Call function
    vector<int> ans = obj.boundary(root);

    // Print result
    cout << "Boundary Traversal: ";

    for (int x : ans) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}