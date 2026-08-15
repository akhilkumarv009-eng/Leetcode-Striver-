#include <iostream>
#include <vector>
using namespace std;
struct node{
    int data;
    struct node *next;
};
struct node * create(vector <int> &arr,int n)
{
    struct node*head=new node();
    head->data=arr[0];
    head->next =NULL;
    struct node *q=head;
    for(int i=1;i<n;i++)
    {
        struct node * p=new node();
        p->data=arr[i];
        p->next=NULL;
        q->next=p;
        q=p;
    }
    return head;
}
struct node * oddAndEven(struct node * head)
{
    struct node * p=head;
    struct node *first,*second;
    first=new node();
    second=new node();
    first->data=0;
    first->next=NULL;
    second->data=0;
    second->next=NULL;
    struct node *f,*s;
    f=first;
    s=second;
    struct node *temp;
    while(p!=NULL)
    {
        if(p->data%2!=0)
        {
           temp=new node();
           temp->data=p->data;
           temp->next=NULL;
           f->next=temp;
           f=f->next;
        }
        else
        {
            temp=new node();
            temp->data=p->data;
            temp->next=NULL;
            s->next=temp;
            s=s->next;
        }
        p=p->next;
    }
    first=first->next;
    s->next=first;
    second=second->next;
    return second;
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
   vector <int> arr={1,2,3,4,5,6};
   struct  node *head=create(arr,arr.size());
   display(head);
   struct node * ans=oddAndEven(head);
   display(ans);
}