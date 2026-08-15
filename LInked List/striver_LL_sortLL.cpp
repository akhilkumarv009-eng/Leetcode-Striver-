#include <iostream>
#include <vector>
using namespace std;
struct node{
    int data;
    struct node * next;

};

struct node * create(vector <int> &arr,int len)
{
    struct node *head=new node();
    head->data=arr[0];
    head->next=NULL;
    struct node *q=head;
    for(int i=1;i<len;i++)
    {
        struct node *p=new node();
        p->data=arr[i];
        p->next=NULL;
        q->next=p;
        q=p;
    }
    return head;
}
struct node * merge(struct node *list1,struct node *list2)
{
    struct node *list3;
    struct node *p;
    struct node *q,*r;
    q=list1;
    r=list2;
    if(q->data>=r->data)
    {
        list3=r;
        r=r->next;
    }
    else
    {
        list3=q;
        q=q->next;
    }
    p=list3;
    while(q!=NULL && r!=NULL)
    {
       if(q->data>r->data)
       {
        p->next=r;
        p=p->next;
        r=r->next;
       }
       else
       {
        p->next=q;
        p=p->next;
        q=q->next;
       }
    }
    while(q!=NULL)
    {
        p->next=q;
        p=p->next;
        q=q->next;
    }
    while(r!=NULL)
    {
        p->next=r;
        p=p->next;
        r=r->next;
    }
    return list3;
}
struct node *middleNode(struct node *head)
{
    struct node *fast,*slow;
    fast=slow=head;
    fast=fast->next;
    while(fast!=NULL && fast->next!=NULL)
    {
       fast=fast->next->next;
       slow=slow->next;
    }
    return slow;

}
struct node *mergesort(struct node *list)
{
    if(list==NULL || list->next==NULL)
    return list;
    else
    {
      struct node *middle=middleNode(list);
      struct node *left=list;
      struct node *right=middle->next;
      middle->next=NULL;
      left=mergesort(left);
      right=mergesort(right);
      return merge(left,right);
    }
}
void display(struct node * p)
{
    while(p!=NULL)
    {
        cout << p->data << " ";
        p=p->next;
    }
    cout << endl;
}
int main()
{
 vector<int> arr={3,5,4,2};
 int n=5;
 struct node *head= create(arr,arr.size());
 struct node *ans=mergesort(head);
 display(ans);
}