#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

    void findparent(TreeNode* root,
                    unordered_map<TreeNode*, TreeNode*> &parent)
    {
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            TreeNode* cur = q.front();
            q.pop();

            if(cur->left)
            {
                parent[cur->left] = cur;
                q.push(cur->left);
            }

            if(cur->right)
            {
                parent[cur->right] = cur;
                q.push(cur->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k)
    {
        unordered_map<TreeNode*, TreeNode*> parent;

        findparent(root, parent);

        queue<TreeNode*> q;
        q.push(target);

        int level = 0;

        unordered_map<TreeNode*, bool> vis;
        vis[target] = true;

        while(!q.empty())
        {
            int n = q.size();

            if(level++ == k)
                break;

            for(int i = 0; i < n; i++)
            {
                TreeNode* cur = q.front();
                q.pop();

                if(cur->left && !vis[cur->left])
                {
                    q.push(cur->left);
                    vis[cur->left] = true;
                }

                if(cur->right && !vis[cur->right])
                {
                    q.push(cur->right);
                    vis[cur->right] = true;
                }

                if(parent[cur] && !vis[parent[cur]])
                {
                    q.push(parent[cur]);
                    vis[parent[cur]] = true;
                }
            }
        }

        vector<int> ans;

        while(!q.empty())
        {
            TreeNode* a = q.front();
            q.pop();

            ans.push_back(a->val);
        }

        return ans;
    }
};