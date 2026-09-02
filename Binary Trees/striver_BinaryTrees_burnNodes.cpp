#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
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


// STEP 1: Create parent mapping
void markParents(TreeNode* root,
                 unordered_map<TreeNode*, TreeNode*>& parent)

{
    parent[root] = NULL;
     
   queue<TreeNode*> q;
   q.push(root);
   while(!q.empty())
   {
     TreeNode* cur = q.front();
     q.pop();
     if(cur->left)
     {
        parent[cur->left]=cur;
        q.push(cur->left);
     }
     if(cur->right)
     {
        parent[cur->right]=cur;
        q.push(cur->right);
     }

   }

}


// STEP 2: BFS / Burn the tree
int burnTree(TreeNode* root,
             unordered_map<TreeNode*, TreeNode*>& parent)
{
    int maxi=0;
    queue<pair<TreeNode*,int>> q;
    q.push({root,0});
    unordered_map<TreeNode*, bool> vis;
    vis[root]=true;
    while(!q.empty())
    {
        int n = q.size();
        for(int i = 0 ; i < n ; i ++)
        {
            auto it = q.front();
            q.pop();
            maxi=max(maxi,it.second);
            TreeNode* cur = it.first;
            if(cur->left && !vis[cur->left])
            {
                q.push({cur->left,it.second+1});
                vis[cur->left]=true;
            }
            if(cur->right && !vis[cur->right])
            {
                q.push({cur->right,it.second+1});
                vis[cur->right]=true;
            }
            if(parent[cur] && !vis[parent[cur]])
            {
                q.push({parent[cur],it.second+1});
                vis[parent[cur]]=true;
            }
        }

    }
    return maxi;


}


// STEP 3: Main function
int minimumTime(TreeNode* root, TreeNode* target)
{
    unordered_map<TreeNode*, TreeNode*> parent;

    TreeNode* startNode = NULL;

    // Create parent mapping
    markParents(root, parent);

    // Burn tree using BFS
    return burnTree(target, parent);
}


int main()
{
    /*
              1
             / \
            2   3
           / \   \
          4   5   6
             /
            7

        Starting node = 5
    */

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->right = new TreeNode(6);

    root->left->right->left = new TreeNode(7);

    TreeNode* target = root->left->right;

    cout << minimumTime(root, target) << endl;

    return 0;
}