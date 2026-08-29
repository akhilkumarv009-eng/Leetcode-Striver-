#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x)
    {
        val = x;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> ans;

        if (root == NULL)
            return ans;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty())
        {
            int len = q.size();
            vector<int> temp;

            for (int i = 0; i < len; i++)
            {
                TreeNode* nod = q.front();
                q.pop();

                if (nod != NULL)
                {
                    temp.push_back(nod->val);

                    if (nod->left != NULL)
                        q.push(nod->left);

                    if (nod->right != NULL)
                        q.push(nod->right);
                }
            }

            ans.push_back(temp);
        }

        return ans;
    }
};

int main()
{
    /*
            5
           / \
          3   4
         / \
        1   2
    */

    TreeNode* root = new TreeNode(5);

    root->left = new TreeNode(3);
    root->right = new TreeNode(4);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(2);

    Solution obj;

    vector<vector<int>> result = obj.levelOrder(root);

    // Print level order
    for (vector<int> level : result)
    {
        for (int x : level)
        {
            cout << x << " ";
        }

        cout << endl;
    }

    return 0;
}