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
    display(head);
}