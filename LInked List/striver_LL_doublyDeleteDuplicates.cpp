#include <iostream>
#include <vector>
using namespace std;
struct node {
    int data;
    struct node *prev,*next;
};
struct node * create(vector <int> & arr,int len)
{
    struct node * head=new node();
    head->data=arr[0];
    head->next=head->prev=NULL;
    struct node * p=head;
    for(int i=1;i<len;i++)
    {
        struct node * q=new node();
        q->data=arr[i];
        q->prev=p;
        q->next=NULL;
        p->next=q;
        p=p->next;
    }
    return head;
}
void display(struct node *p)
{
    if(p==NULL)
    cout << "0";
    while(p!=NULL)
    {
        cout <<p->data << " ";
        p=p->next;
    }
}
struct node * doublyDeleteDuplicates(struct node * head)
{
    if(head==NULL || head->next==NULL)
    return head;
    struct node *q=head;
    struct node * p,*r;
    p=r=NULL;
    while(q!=NULL)
    {
       if(q==head)
       q=q->next;
       else
       {
         p=q->prev;
         r=q->next;
         if(p->data==q->data)
         {
            if(q->next!=NULL)
            {
                p->next=r;
                r->prev=p;
                struct node *s=q;
                q=q->next;
                s->next=s->prev=NULL;
                delete s;
            }
            else
            {
                p->next=NULL;
                q->prev=NULL;
                delete q;
                q=NULL;
            }

         }
         else
         {
            q=q->next;
         }
       }
    }
    return head;
}
int main()
{
   vector <int> arr={1,1,1};
   struct node * head=create(arr,arr.size());
   head=doublyDeleteDuplicates(head);
   display(head);
   
}