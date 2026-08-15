#include <iostream>
#include<map>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};
//10 -> 20 -> 30 -> 40 -> 50
 //            ^           |
  //           |___________|


int lenghtOfLoop(struct Node *head)
{
    struct Node * p;
    p=head;
    struct Node *q;
    q=head;
    while(p!=NULL && p->next!=NULL)
    {
        p=p->next->next;
        q=q->next;
        if(p==q)
        {
            q=head;
            while(p!=q)
            {
                p=p->next;
                q=q->next;
            }
            int count=1;
            q=q->next;
            while(p!=q)
            {
                q=q->next;
                count++;
            }
            return count;
        }
    }
    return -1;

}

int main() {
    // Create nodes
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(50);

    // Link nodes
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    // Create a loop:
    // 50 -> 30
    fifth->next = third;

    // Write your loop detection code here
    int start=lenghtOfLoop(head);
    if(start!=-1)
    cout << start;
    else
    cout << "-1";
}