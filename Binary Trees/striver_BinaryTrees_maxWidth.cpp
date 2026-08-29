#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() {
        val = 0;
        left = NULL;
        right = NULL;
    }

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }

    TreeNode(int x, TreeNode* left, TreeNode* right) {
        val = x;
        this->left = left;
        this->right = right;
    }
};

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {

        if(root == NULL)
            return 0;

        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        int wid = 1;

        while(!q.empty())
        {
            int n = q.size();

            long long mmin = q.front().second;
            long long first, last;

            for(int i = 0; i < n; i++)
            {
                long long cur = q.front().second - mmin;

                if(i == 0)
                    first = cur;

                if(i == n - 1)
                    last = cur;

                TreeNode* node = q.front().first;
                q.pop();

                if(node->left)
                    q.push({node->left, 2 * cur + 1});

                if(node->right)
                    q.push({node->right, 2 * cur + 2});
            }

            wid = max(wid, (int)(last - first + 1));
        }

        return wid;
    }
};

int main() {

    /*
              1
             / \
            3   2
           /     \
          5       9
         /         \
        6           7
    */

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(3);
    root->right = new TreeNode(2);

    root->left->left = new TreeNode(5);
    root->right->right = new TreeNode(9);

    root->left->left->left = new TreeNode(6);
    root->right->right->right = new TreeNode(7);

    Solution obj;

    cout << obj.widthOfBinaryTree(root) << endl;

    return 0;
}