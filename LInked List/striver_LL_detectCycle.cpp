#include <iostream>
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


int cycle(struct Node * head)
{
    struct Node *p;
    struct Node *q;
    p=q=head;
    while (p != NULL && p->next != NULL)
{
    p = p->next->next;
    q = q->next;

    if (p == q)
        return 1;
}
return 0;
    return 0;
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
    int x= cycle(head);
    if(x==0)
    cout << "no loop";
    else
    cout << "loop exits";

    return 0;
}