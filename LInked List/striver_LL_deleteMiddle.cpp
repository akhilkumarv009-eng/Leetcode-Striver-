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
int lenghtNode(struct node * p)
{
    int len=0;
    while(p!=NULL)
    {

        len++;
        p=p->next;
    }
    return len;
}
struct node * deleteMiddle(struct node *head)
{
    if (head == NULL)
        return NULL;

    // Only one node
    if (head->next == NULL)
    {
        delete head;
        return NULL;
    }

    struct node *p;
    p=head;
    int len=lenghtNode(p);
    struct node *fast,*slow,*temp,*temp2;
    fast=slow=head;
    temp=NULL;
    
    
      while(fast!=NULL && fast->next!=NULL)
      {
        fast=fast->next->next;
        temp=slow;
        slow=slow->next;
      } 
      temp2=slow;
      temp->next=slow->next;
      delete temp2;
    
    return head;
}
int main()
{
   vector<int> arr={1,2,3,4};
 int n=5;
 struct node *head= create(arr,arr.size());
 struct node *ans=deleteMiddle(head);
 display(ans);
}