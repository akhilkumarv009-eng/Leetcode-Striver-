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
struct node * doublyDeleteKey(struct node * head,int key)
{
    if(head==NULL)
    return NULL;
    struct node * q=head;
    struct node *p,*s;
    p=s=NULL;
    while(q!=NULL)
    {
        if(head==NULL)return NULL;
        else if(head->next==NULL)
        {
            if(head->data==key)return NULL;
            else
            return head;
        }
        p=q->prev;
        s=q->next;
        if(q->data==key)
        {
            if(q==head)
            {
                struct node * r=head;
                head=head->next;
                r->next=NULL;
                head->prev=NULL;
                q=head;
                delete r;
            }
            else
            {
                if(q->next!=NULL)
                {
                struct node * r=q;
                p->next=q->next;
                s->prev=q->prev;
                q=q->next;
                r->next=r->prev=NULL;
                delete r;
                }
                else
                {
                    p->next=NULL;
                    q->prev=NULL;
                    delete q;
                    q=NULL;

                }
            }
        }
        else
        {
            q=q->next;
        }
    }
    return head;
}
int main()
{
   vector <int> arr={2,3,1};
   struct node * head=create(arr,arr.size());
   head=doublyDeleteKey(head,1);
   display(head);
   
}