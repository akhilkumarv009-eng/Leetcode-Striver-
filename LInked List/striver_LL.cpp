#include <iostream>
#include <vector>
using namespace std;
struct node{
    int data;
    struct node *next;
};
struct node * create(vector <int> arr , int len)
{
    struct node * p;
    p=new node();
    p->data=arr[0];
    p->next=NULL;
    struct node *head;
    head=p;
    for(int i=1;i<len;i++)
    {
        struct node *q;
        q=new node();
        q->data=arr[i];
        p->next=q;
        q->next=NULL;
        p=q;
    }
    return head;
}
struct node * insert(struct node * head,int x)
{
    struct node * temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    struct node * q=new node();
    q->data=x;
    q->next=NULL;
    temp->next=q;
    return head;
}
struct node * insertHead(struct node * head,int x)
{
    struct node * p;
    p=new node();
    p->data=x;
    p->next=head;
    head=p;
    return head;
}
struct node * deleteHead(struct node * head)
{
    struct node *p;
    p=head->next;
    head->next=NULL;
    head=p;
    return head;

}
int lenght(struct node * head)
{
    int x=0;
    struct node *p=head;
    while(p!=NULL)
    {
        x++;
        p=p->next;
    }
    return x;
}
int search(struct node * head,int x)
{
    struct node * p=head;
    int y=0;
    while(p!=NULL)
    {
        y++;
        if(x==p->data)
        {
            return y;
        }     
        p=p->next;
    }
    return -1;
}
int main()
{ 
    vector<int> arr = {10, 20, 30, 40,2,3,4};

    node* head = create(arr, arr.size());
   // head=insert(head,10);
    //head=insertHead(head,150);
    //head=deleteHead(head);
    //node * temp=head;
   // while(temp!=NULL)
    {
        //cout << temp->data<< endl;
     //   temp=temp->next;
    }
    //int len=lenght(head);
    int len=search(head,20);
    cout << len;


return 0;
}