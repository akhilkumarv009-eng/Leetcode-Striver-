#include <iostream>
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
    bool isSameTree(TreeNode* p, TreeNode* q) {

        // Both trees are empty
        if (p == NULL && q == NULL)
            return true;

        // One is empty and the other is not
        if (p == NULL || q == NULL)
            return false;

        // Values are different
        if (p->val != q->val)
            return false;

        // Check left and right subtrees
        return isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }
};

int main() {
    // Tree 1
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);

    // Tree 2
    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);

    Solution obj;

    if (obj.isSameTree(p, q))
        cout << "Same Tree" << endl;
    else
        cout << "Different Trees" << endl;

    return 0;
}