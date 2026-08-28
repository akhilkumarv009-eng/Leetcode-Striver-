#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// YOU WRITE THIS FUNCTION
bool rootToNodePath(Node* root, int target, vector<int>& path) {

     if(root==NULL)return false;

     path.push_back(root->data);
     if(root->data==target)return true;

     if( rootToNodePath(root->left,target,path) || rootToNodePath(root->right,target,path))
     return true;

     path.pop_back();
     return false;

}

int main() {

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    int target;
    cin >> target;

    vector<int> path;

    if (rootToNodePath(root, target, path)) {
        for (int x : path)
            cout << x << " ";
    }
    else {
        cout << "Node not found";
    }

    return 0;
}