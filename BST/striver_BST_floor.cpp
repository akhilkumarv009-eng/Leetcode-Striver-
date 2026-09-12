#include <iostream>
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

// YOU WRITE THIS
int findfloor(TreeNode* root, int x) {
   
   int ans = 0; 
   while(root!=NULL)
   {
      if(root->val > x)
      {
        root = root->left;
      }
      else
      {
         ans = root->val;
         root = root->right;
      }
   }
   return ans;

}


int main() {

    // Create BST
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(8);
    root->right->right = new TreeNode(13);
    root->right->left = new TreeNode(17);
    root->left->right->left=new TreeNode(6);

    

    int x = 9;

    cout << "Ceil: " << findfloor(root, x) << endl;

    return 0;
}