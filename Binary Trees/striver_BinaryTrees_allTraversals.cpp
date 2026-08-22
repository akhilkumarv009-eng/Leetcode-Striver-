#include <iostream>
#include <vector>
#include <stack>
using namespace std;
struct node
{
    int data;
    struct node * left;
    struct node *right;
    node(int val)
    {
        data=val;
        left=right=NULL;
    }

};
int main()
{
    struct node * root=new node(1);
    root->left=new node(2);
    root->right=new node(5);
    root->left->left=new node(3);
    root->left->right=new node(4);
    root->right->left=new node(6);
    root->right->right=new node(7);

    vector<int> preorder;
    vector<int> postorder;
    vector<int> inorder;

    stack<pair<node*,int>> st;

    st.push({root,1});
    while(!st.empty())
    { 
        auto &it = st.top();

        if(it.second==1)
        {
            preorder.push_back(it.first->data);
            it.second++;
            if(it.first->left!=NULL)
            {
                st.push({it.first->left,1});
            }
        }
        else if(it.second==2)
        {
            inorder.push_back(it.first->data);
            it.second++;
            if(it.first->right!=NULL)
            {
                st.push({it.first->right,1});
            }
        }
        else
        {
            postorder.push_back(it.first->data);
            st.pop();
        }

    }
    for(auto it : preorder)
    {
        cout << it << " ";
    }
    cout << endl;
     for(auto it : inorder)
    {
        cout << it << " ";
    }
    cout << endl;
     for(auto it : postorder)
    {
        cout << it << " ";
    }
    cout << endl;
}