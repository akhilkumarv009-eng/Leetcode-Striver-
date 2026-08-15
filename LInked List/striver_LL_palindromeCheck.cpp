#include <iostream>
#include <vector>
using namespace std;
struct node{
    int data;
    struct node * next;
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
int listlenght(struct node *head)
{
    struct node *p=head;
    int count = 0;
    while(p!=NULL)
    {
        count ++;
        p=p->next;
    }
    return count;
}
struct node * middleNode(struct node *head)
{
    struct node * fast;
    struct node * slow;
    fast=slow=head;
    while(fast!=NULL && fast->next!=NULL)
    {
       fast=fast->next->next;
       slow=slow->next;
    }
    return slow;
}
struct node*reNode(struct node *head)
{
    struct node *p,*q,*r;
    q=head;
    p=r=NULL;
    while(q!=NULL)
    {
       r=q->next;
       q->next=p;
       p=q;
       q=r;

    }
    return p;
}
int palindromeCheck(struct node * head , int n)
{
   struct node * p=head;
   struct node *mid=middleNode(head);
   struct node *q,*r,*s,*reverse;
   if(listlenght(head)%2!=0)
    reverse=reNode(mid->next);
   else if(listlenght(head)%2==0)
   {
   reverse=reNode(mid);
   }
   struct node *pointer=reverse;
   while(pointer!=NULL)
   {
    if(p->data!=pointer->data)
    return -1;
    else{
        p=p->next;
        pointer=pointer->next;
    }
   }
   return 1;
}
int main()
{
   vector <int> arr ={3,7,5,5,7,3};
   struct node * head=create(arr,arr.size());
   int len=listlenght(head);
   int c=palindromeCheck(head ,len);

}