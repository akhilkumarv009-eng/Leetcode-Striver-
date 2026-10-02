#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

class node{
    public:
    int maxnode;
    int minnode;
    int maxsize;
    node(int maxnode,int minnode,int maxsize)
    {
        this->maxnode=maxnode;
        this->minnode=minnode;
        this->maxsize=maxsize;
    }
};

class Solution{
    node largestBST1(TreeNode* root)
    {
        if(!root) return node(INT_MIN,INT_MAX,0);

        node leftnode = largestBST1(root->left);
        node rightnode = largestBST1(root->right);

        if(leftnode.maxnode < root->val && rightnode.minnode > root->val)
        return node(max(leftnode.maxnode,root->val),min(rightnode.minnode,root->val),leftnode.maxsize + rightnode.maxsize+1);

        return node(INT_MAX,INT_MIN,max(leftnode.maxsize,rightnode.maxsize));
    }

    public:
        int largestBST(TreeNode* root){
            return largestBST1(root).maxsize;
        }
};

int main() {

    TreeNode* root = new TreeNode(50);

    root->left = new TreeNode(30);
    root->right = new TreeNode(60);

    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(20);

    root->right->left = new TreeNode(45);
    root->right->right = new TreeNode(70);

    root->right->right->left = new TreeNode(65);
    root->right->right->right = new TreeNode(80);

    Solution obj;

    cout << obj.largestBST(root) << endl;

    return 0;
}