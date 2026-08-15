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
void display(struct node * p)
{
    while(p!=NULL)
    {
        cout << p->data << " ";
        p=p->next;
    }
    cout << endl;
}
struct node *rev(struct node *head)
{
   if(head==NULL || head->next==NULL)
   return head;
   else
   {
     struct node *p,*q,*r;
     p=q=NULL;
     q=head;
     while(q!=NULL)
     {
        r=q->next;
        q->next=p;
        p=q;
        q=r;
     }
     return p;
   }
}
struct node * add1(struct node * head)
{
    if(head==NULL)
    return NULL;
    struct node *head1=rev(head);
    int carry=1;
    struct node *temp;
    temp=head1;
    while(temp!=NULL)
    {
        if(carry==1)
        {
            int num=temp->data;
            if(num+1==10)
            {
                temp->data=0;
                carry=1;
            }
            else
            {
                temp->data=num+1;
                carry=0;
            }
        }
        temp=temp->next;
    }
    if(carry==1)
    {
        struct node *temp1=head1;
        while(temp1->next!=NULL)
        {
            temp1=temp1->next;
        }
        struct node * q=new node();
        q->data=1;
        q->next=NULL;
        temp1->next=q;
    }
    struct node * ans=rev(head1);
    return ans;

}
int main()
{
  vector<int> arr={9,9,9};
  struct node *head= create(arr,arr.size());
  struct node *ans=add1(head);
   display(ans);
}