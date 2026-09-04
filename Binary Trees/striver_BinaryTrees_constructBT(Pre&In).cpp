#include <iostream>
#include <vector>
#include <map>
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

    TreeNode* build(vector<int>& preorder, int ps, int pe,
                    vector<int>& inorder, int is, int ie,
                    map<int, int>& mp)
    {
        if (ps > pe || is > ie)
            return NULL;

        TreeNode* root = new TreeNode(preorder[ps]);

        int inroot = mp[preorder[ps]];
        int numleft = inroot - is;

        root->left = build(preorder,
                           ps + 1,
                           ps + numleft,
                           inorder,
                           is,
                           inroot - 1,
                           mp);

        root->right = build(preorder,
                            ps + numleft + 1,
                            pe,
                            inorder,
                            inroot + 1,
                            ie,
                            mp);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        map<int, int> mp;

        for (int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;

        return build(preorder,
                     0,
                     preorder.size() - 1,
                     inorder,
                     0,
                     inorder.size() - 1,
                     mp);
    }
};

int main()
{
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    Solution obj;

    TreeNode* root = obj.buildTree(preorder, inorder);

    cout << "Tree constructed successfully!" << endl;

    return 0;
}