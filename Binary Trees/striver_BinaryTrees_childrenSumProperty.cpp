#include <iostream>
#include <queue>
using namespace std;

class BinaryTreeNode {
public:
    int data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

// ======================================================
// YOU ONLY NEED TO WRITE THIS FUNCTION
// ======================================================

void changeTree(BinaryTreeNode* root) {
    
    if(root==NULL)return ;
    int sum=0;
    if(root->left)sum+=root->left->data;
    if(root->right)sum+=root->right->data;
    if(sum > root->data)root->data=sum;
    else
    {
        if(root->left)root->left->data=root->data;
        if(root->right)root->right->data=root->data;

    }
    changeTree(root->left);
    changeTree(root->right);

    int tot=0;
    if(root->left)tot+=root->left->data;
    if(root->right)tot+=root->right->data;
    if(tot > root->data)root->data=tot;
    
    
}

// ======================================================
// FRAMEWORK - DO NOT CHANGE
// ======================================================

// Print tree level by level
void printTree(BinaryTreeNode* root) {
    if (root == NULL)
        return;

    queue<BinaryTreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        BinaryTreeNode* current = q.front();
        q.pop();

        cout << current->data << " ";

        if (current->left != NULL)
            q.push(current->left);

        if (current->right != NULL)
            q.push(current->right);
    }

    cout << endl;
}

// Delete tree
void deleteTree(BinaryTreeNode* root) {
    if (root == NULL)
        return;

    deleteTree(root->left);
    deleteTree(root->right);

    delete root;
}

// Create a test tree
BinaryTreeNode* createTree() {

    BinaryTreeNode* root = new BinaryTreeNode(50);

    root->left = new BinaryTreeNode(7);
    root->right = new BinaryTreeNode(2);

    root->left->left = new BinaryTreeNode(3);
    root->left->right = new BinaryTreeNode(5);

    root->right->left = new BinaryTreeNode(1);
    root->right->right = new BinaryTreeNode(1);

    return root;
}

int main() {

    BinaryTreeNode* root = createTree();

    cout << "Before: ";
    printTree(root);

    changeTree(root);

    cout << "After:  ";
    printTree(root);

    deleteTree(root);

    return 0;
}