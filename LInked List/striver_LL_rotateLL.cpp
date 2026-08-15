#include <iostream>
#include <vector>
using namespace std;
struct node{
    int data;
    struct node * next;
};
struct node * create(vector <int> &arr,int n)
{
  struct node * head=new node();
  head->data=arr[0];
  head->next=NULL;
  struct node *p=head;
  for(int i=1;i<n;i++)
  {
    struct node * q=new node();
    q->data=arr[i];
    q->next=NULL;
    p->next=q;
    p=p->next;
  }
  return head;

}
int len(struct node * p)
{
    int count=0;
    while(p!=NULL)
    {
        count++;
        p=p->next;
    }
    return count;
}
struct node *rotateLL(struct node * head,int k)
{
    if(head==NULL || k==0 || head->next==NULL)return head;
   int length = len(head);
    k = k % length;

    if(k == 0)
        return head;
    struct node * fast,*slow;
    slow=fast=head;
    for(int i=0;i<k;i++)
    {
      fast=fast->next;
    }
    while(fast->next!=NULL)
    {
        fast=fast->next;
        slow=slow->next;
    }
    struct node * q=slow->next;
    slow->next=NULL;
    fast->next=head;
    head=q;
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
    vector<int> arr ={1,2,3,4,5};
    struct node * head=create(arr,arr.size());
    head=rotateLL(head,2);
    display(head);
}