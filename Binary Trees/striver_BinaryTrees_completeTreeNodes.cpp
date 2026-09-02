#include <iostream>
#include <cmath>
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

class Solution {
public:

    int findleft(TreeNode* root)
    {
        int cnt = 0;

        while(root != NULL)
        {
            cnt++;
            root = root->left;
        }

        return cnt;
    }

    int findright(TreeNode* root)
    {
        int cnt = 0;

        while(root != NULL)
        {
            cnt++;
            root = root->right;
        }

        return cnt;
    }

    int countNodes(TreeNode* root)
    {
        if(root == NULL)
            return 0;

        int rh = 0;
        int lh = 0;

        if(root->left)
        {
            rh = findleft(root->left);
        }

        if(root->right)
        {
            lh = findright(root->right);
        }

        if(rh == lh)
        {
            int n = pow(2, rh + 1) - 1;
            return n;
        }
        else
        {
            return 1 + countNodes(root->left)
                     + countNodes(root->right);
        }
    }
};

int main()
{
    /*
              1
             / \
            2   3
           / \ /
          4  5 6

        Expected = 6
    */

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->left = new TreeNode(6);

    Solution obj;

    cout << "Number of nodes = "
         << obj.countNodes(root) << endl;

    return 0;
}