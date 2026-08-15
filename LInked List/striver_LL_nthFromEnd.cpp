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
struct node * deleteNth(struct node *head,int n)
{
   struct node *fast=head;;
   struct node *slow=head;
   for(int i=0;i<n;i++)
   {
     fast=fast->next;
   }
   if(fast==NULL)
   {
    return head->next;
   }
   while(fast->next!=NULL)
   {
    fast=fast->next;
    slow=slow->next;
   }
   struct node *x=slow->next;
   slow->next=x->next;
   free(x);
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
int main()
{
 vector<int> arr={1,2,3,4,5};
 int n=5;
 struct node *head= create(arr,arr.size());
 struct node *ans=deleteNth(head,n);
 display(ans);

}