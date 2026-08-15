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
struct node * reverseKGroup(struct node * head,int k)
{
    if (head == NULL || k == 1)
    return head;
    struct node *reme=NULL;
    struct node * p=head;
    while(p!=NULL)
    {
        int checker=0;
        struct node * q=p;
        if(p==head)
        {
            for(int i=1;i<k;i++)
            {
                if(q!=NULL && q->next!=NULL)
                {
                   q=q->next;
                }
                else
                {
                    checker=1;
                    break;
                }
            }
            if(checker==1)
            break;
            else
           {
               struct node * nxt=q->next;
               q->next=NULL;
               struct node * reverse=rev(p);
               head=reverse;
               p->next=nxt;
               if(reme!=NULL)
               {
                reme->next=reverse;
               }
               reme=p;
               p=nxt;
            }
        }
        
        else
        {
          for(int i=1;i<k;i++)
           {
                if(q!=NULL && q->next!=NULL)
                {
                   q=q->next;
                }
                else
                {
                    checker=1;
                    break;
                }
            } 
           if(checker==1)
            break;
           else
           {
               struct node * nxt=q->next;
               q->next=NULL;
               
               struct node * reverse=rev(p);
               p->next=nxt;
               if(reme!=NULL)
               {
                reme->next=reverse;
               }
               reme=p;
               p=nxt;
            }
        }
        
    }
    return head;
}
int main()
{
   vector <int> arr={3,2,1,6,5,4,8,7};
   struct node * head=create(arr,arr.size());
   head=reverseKGroup(head,3);
   display(head);
   
}