#include <iostream>
#include <vector>
#include <queue>
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> ans;

        if (root == NULL)
            return ans;

        queue<TreeNode*> q;
        q.push(root);

        int flag = 1;

        while (!q.empty()) {

            flag = 1 - flag;

            int n = q.size();

            vector<int> temp;

            for (int i = 0; i < n; i++) {

                temp.push_back(q.front()->val);

                if (q.front()->left != NULL)
                    q.push(q.front()->left);

                if (q.front()->right != NULL)
                    q.push(q.front()->right);

                q.pop();
            }

            if (flag == 0) {
                ans.push_back(temp);
            }
            else {
                reverse(temp.begin(), temp.end());
                ans.push_back(temp);
            }
        }

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
    */

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->right = new TreeNode(6);

    Solution obj;

    vector<vector<int>> result = obj.zigzagLevelOrder(root);

    for (auto level : result) {
        for (auto value : level) {
            cout << value << " ";
        }
        cout << endl;
    }

    return 0;
}