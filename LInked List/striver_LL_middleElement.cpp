#include <iostream>
#include <vector>
using namespace std;
struct node{
    int data;
    struct node * next;
};
struct node * create(vector <int> & arr,int len)
{
    struct node * head= new node();
    head->data=arr[0];
    head->next=NULL;
    struct node *q=head;
    for(int i=1;i<len;i++)
    {
        struct node *p=new node ;
        p->data=arr[i];
        p->next=NULL;
        q->next=p;
        q=p;
    }
    return head;

}
int len(struct node *head)
{
    struct node *p;
    p=head;
    int x=0;
    while(p!=NULL)
    {
      x++;
      p=p->next;
    }
    return x;
}
int main()
{
   vector <int> arr={1,2,3,4,5,6,7};
   struct node * head=create(arr,arr.size());
   int h=len(head);
   int y=h/2;
   struct node *p=head;
   for(int i=0;i<y;i++)
   {
    p=p->next;
   }
   cout << p->data;
}