#include <iostream>
#include <vector>
using namespace std;
struct node{
    int data;
    struct node * prev;
    struct node * next;
};
struct node * create(vector <int> & arr ,int len)
{
    struct node * head=new node();
    head->data=arr[0];
    head->prev=head->next=NULL;
    struct node *p=head;
    for(int i=1;i<len;i++)
    {
        struct node * q = new node();
        q->data=arr[i];
        p->next=q;
        q->prev=p;
        q->next=NULL;
        p=q;
    }
    return head;
}
struct node * insertHead(struct node *head,int x)
{
    struct node *p=new node();
    p->data=x;
    p->prev=NULL;
    p->next=head;
    head->prev=p;
    head=p;

    return head;
}
struct node *deleteHead(struct node *head)
{
    struct node *p=head;
    p=head->next;
    p->prev=NULL;
    head->next=NULL;
    head=p;

    return head;
}
struct node * reverse(struct node * head)
{
    struct node *p,*q,*r;
    q=head;
    while(q!=NULL)
    {
        p=q->prev;
        r=q->next;
        q->prev=r;
        q->next=p;
        head=q;
        q=r;
    }
    return head;

}
int main()
{
  vector <int> arr={1,2,3,4,5};
  struct node *head;
  head=create(arr,arr.size());
  head=insertHead(head,150);
  head=deleteHead(head);
  head=reverse(head);
  struct node *temp=head;
  while(temp!=NULL)
  {
    cout << temp->data << endl;
    temp=temp->next;
  }

}