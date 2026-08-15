#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) {
        val = x;
        next = NULL;
    }
};
int len(struct ListNode * head)
{
    int len=0;
    while(head!=NULL)
    {
        len++;
        head=head->next;
    }
    return len;
}
// Write only this function
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
   int len1=len(headA);
   int len2=len(headB);
   ListNode *p,*q;
   p=headA;
   q=headB;
   if(len1>len2)
   {
     for(int i=0;i<(len1-len2);i++)
     {
         p=p->next;
     }
   }
   else
   {
     for(int i=0;i<(len2-len1);i++)
     {
         q=q->next;
     }
   }
   while(p!=NULL && q!=NULL)
   {
     if(p==q)
     return p;
     else
     {
        p=p->next;
        q=q->next;
     }
   }
   return NULL;
}

int main() {

    // Common Part
    ListNode *common = new ListNode(8);
    common->next = new ListNode(4);
    common->next->next = new ListNode(5);

    // List A
    ListNode *headA = new ListNode(4);
    headA->next = new ListNode(1);
    headA->next->next = common;

    // List B
    ListNode *headB = new ListNode(5);
    headB->next = new ListNode(6);
    headB->next->next = new ListNode(1);
    headB->next->next->next = common;

    ListNode *ans = getIntersectionNode(headA, headB);

    if (ans)
        cout << ans->val << endl;
    else
        cout << "No Intersection\n";
}