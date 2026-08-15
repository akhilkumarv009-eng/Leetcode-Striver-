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
struct node * sort0sand1s(struct node *head)
{
    if(head==NULL || head->next==NULL)return head;
    struct node *one,*two,*zero;
    one=new node();
    two=new node();
    zero=new node();
    one->data=-1;
    one->next=NULL;
    two->data=-1;
    two->next=NULL;
    zero->data=-1;
    zero->next=NULL;
    struct node *p,*q,*r,*s;
    s=head;
    p=zero;
    q=one;
    r=two;
    while(s!=NULL)
    {
        if(s->data==0)
        {
           p->next=s;
           p=p->next;
           s=s->next;
           p->next=NULL;
        }
        else if(s->data==1)
        {
           q->next=s;
           q=q->next;
           s=s->next;
           q->next=NULL;
        }
        else if(s->data==2)
        {
           r->next=s;
           r=r->next;
           s=s->next;
           r->next=NULL;
        }
    }
    
        if(one->next!=NULL)
        {
            p->next=one->next;
            q->next=two->next;
        }
        else
        {
            p->next=two->next;
        }
        return zero->next;

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
 vector<int> arr={1,1,1,1};
 struct node *head= create(arr,arr.size());
  struct node *ans=sort0sand1s(head);
  display(ans);
}