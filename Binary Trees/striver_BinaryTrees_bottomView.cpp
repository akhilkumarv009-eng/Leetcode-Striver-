#include <iostream>
#include <map>
#include <queue>
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
void bottomView(Node* root) {

    map<int,int> mp;
    queue<pair<Node*,int>> q;

    q.push({root,0});

    while(!q.empty())
    {
        auto it = q.front();
        q.pop();
        Node* node=it.first;
        int col=it.second;
        mp[col]=node->data;
        if(node->left!=NULL)
        {
            q.push({node->left,col-1});
        }
        if(node->right!=NULL)
        {
            q.push({node->right,col+1});
        }
    }

    for(auto x : mp)
    {
        cout << x.second <<" ";
    }



}

int main() {

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(6);

    root->right->right = new Node(7);

    root->left->right->left = new Node(8);
    root->left->right->right = new Node(9);

    bottomView(root);

    return 0;
}