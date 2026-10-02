#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class BSTIterator {
private:
    stack<TreeNode*> st;

    bool reverse;

public:
    BSTIterator(TreeNode* root,bool rev) {
        reverse=rev;
        pushALL(root);
    }
    

    void pushALL(TreeNode* node) {
       if(reverse)
       {
         while(node!=NULL)
         {
            st.push(node);
            node=node->left;
         }
       }
       else
       {
         while(node!=NULL)
         {
            st.push(node);
            node=node->right;
         }
       }
    }

    int next() {

        TreeNode* node = st.top();
        st.pop();

        if(reverse)
        {
            pushALL(node->right);
        }
        else
        {
            pushALL(node->left);
        }

        return node->val;
    }

    bool hasNext() {
        return !st.empty();
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {

        BSTIterator l(root,true);
        BSTIterator r(root,false);

        int i = l.next();
        int j = r.next();
        while(i < j)
        {
           if(i + j == k)return true;
           else if(i + j > k)
            j = r.next();
            else
             i = l.next();
        }
        return false;
        
    }
};