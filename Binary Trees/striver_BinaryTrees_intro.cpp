#include <iostream>
using namespace std;
struct node 
{
    int data;
    struct node * left;
    struct node * right;
    node(int val)
    {
        data=val;
        left=right=NULL;
    }
};
int main()
{
   struct node * root=new node(5);
   root->left=new node(3);
   root->right=new node(4);
}