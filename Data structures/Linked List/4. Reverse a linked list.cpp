#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* head = nullptr;

void Insert(int val)
{
    Node* temp = new Node();
    temp -> data = val;
    temp -> next = NULL;

    if (head == NULL)
    {
        head = temp;
        return;
    }

    Node* ptr = head;
    while (ptr -> next != NULL)
        ptr = ptr -> next;

    ptr -> next = temp;
}

void Print()
{
    Node* ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr -> next;
    }
    printf("\n");
}

struct Node* Reverse(struct Node* head)
{
    struct Node *cur, *prev, *next;
    cur = head;
    prev = NULL;

    while (cur != NULL)
    {
        next = cur-> next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    head = prev;
    return head;
}

int main()
{
    Insert(2);
    Insert(4);
    Insert(6);
    Insert(5); // List : 2 4 6 5

    Print();
    head = Reverse(head);  // Update the head pointer after reversing
    Print();

    return 0;
}
