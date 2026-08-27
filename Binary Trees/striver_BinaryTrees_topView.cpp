#include <iostream>
#include <map>
#include <vector>
#include <queue>
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

void topView(Node* root) {
     
    if (root==NULL)return ;
    vector<int> ans;
    map<int,int> mp;
    queue <pair<Node*,int>> q;

    q.push({root,0});

    while(!q.empty())
    {
        auto it = q.front();
        q.pop();

        Node* node =it.first;
        int col=it.second;

        if(mp.find(col)==mp.end())
        {
            mp.insert({col,node->data});
        }
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
        cout << x.second << " ";
    }



}

int main() {

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->right = new Node(7);

    root->left->right->left = new Node(6);

    topView(root);

    return 0;
}