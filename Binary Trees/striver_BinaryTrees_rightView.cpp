#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {

        vector<int> ans;

        if (root == nullptr)
            return ans;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {

            int n = q.size();
            stack<int> st;

            for (int i = 0; i < n; i++) {

                TreeNode* node = q.front();
                q.pop();

                st.push(node->val);

                if (node->left != nullptr)
                    q.push(node->left);

                if (node->right != nullptr)
                    q.push(node->right);
            }

            // Last node of the current level
            ans.push_back(st.top());
        }

        return ans;
    }
};

int main() {

    /*
             1
            / \
           2   3
            \   \
             5   4

        Right Side View = 1 3 4
    */

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);

    Solution obj;

    vector<int> ans = obj.rightSideView(root);

    cout << "Right Side View: ";

    for (int x : ans) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}