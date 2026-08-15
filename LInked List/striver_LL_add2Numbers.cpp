#include <iostream>
#include <vector>
using namespace std;
struct node{
    int data;
    struct node * next;

};

struct node * create(vector <int> &arr,int len)
{
   if(len == 0)
        return NULL;
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
struct node *add2Numbers(struct node * head1,struct node *head2)
{
   if(head1==NULL)return head2;
   if(head2==NULL)return head1;
   struct node *list1,*list2;
   list1=rev(head1);
   list2=rev(head2);
   struct node *p,*q;
   p=list1;
   q=list2;
   int carry=0;
   struct node *list3=new node();
   list3->data=-1;
   list3->next=NULL;
   struct node *r=list3;
   while(p!=NULL && q!=NULL)
   {
      struct node * temp=new node();
      temp->next=NULL;
      int num=p->data+q->data;
      if(carry==0)
      {
         if(num>=10)
         {
            temp->data=num-10;
            carry=1;
            r->next=temp;
            r=r->next;
            p=p->next;
            q=q->next;
         }
         else
         {
            temp->data=num;
            carry=0;
            r->next=temp;
            r=r->next;
            p=p->next;
            q=q->next;
         }
      }
      else
      {
         num=num+1;
         if(num>=10)
         {
            temp->data=num-10;
            carry=1;
            r->next=temp;
            r=r->next;
            p=p->next;
            q=q->next;
         }
         else
         {
            temp->data=num;
            carry=0;
            r->next=temp;
            r=r->next;
            p=p->next;
            q=q->next;
         }
      }
   }
   while(p!=NULL)
   {
      struct node * temp2=new node();
      int num=p->data;
      if(carry==0)
      {
         temp2->data=num;
         temp2->next=NULL;
         r->next=temp2;
         r=r->next;
         p=p->next;
      }
      else
      {
         num=num+1;
         if(num>=10)
         {
            temp2->data=num-10;
            carry=1;
            r->next=temp2;
            r=r->next;
            p=p->next;
         }
         else
         {
            temp2->data=num;
            carry=0;
            r->next=temp2;
            r=r->next;
            p=p->next;
         }
      }
   }
   while(q!=NULL)
   {
      struct node * temp2=new node();
      int num=q->data;
      if(carry==0)
      {
         temp2->data=num;
         temp2->next=NULL;
         r->next=temp2;
         r=r->next;
         q=q->next;
      }
      else
      {
         num=num+1;
         if(num>=10)
         {
            temp2->data=num-10;
            carry=1;
            r->next=temp2;
            r=r->next;
            q=q->next;
         }
         else
         {
            temp2->data=num;
            carry=0;
            r->next=temp2;
            r=r->next;
            q=q->next;
         }
      }
   }
   if(carry==1)
   {
      struct node * temp3=new node();
      temp3->data=1;
      temp3->next=NULL;
      r->next=temp3;
      r=r->next;
   }
   struct node * ans=rev(list3->next);
   return ans;

}
int main()
{
  vector<int> arr={9,9,9};
  vector<int> arr1={9,9,9};
  struct node *head1= create(arr,arr.size());
  struct node *head2= create(arr1,arr1.size());
  struct node *ans=add2Numbers(head1,head2);
  display(ans);
}