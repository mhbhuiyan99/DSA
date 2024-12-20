#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
};
Node* head = nullptr;

void Insert(int val, int n)
{
    Node* temp1 = new Node();
    temp1 -> data = val;
    temp1 -> next = NULL;
    /*
       At first need to update the address of 'val' with n'th data's address
       then the n-1'th values address with 'val's address

       for Visualizing more easily : https://www.youtube.com/watch?v=0hGxILnKvJk
    */
    if (n == 1)  // Special case: inserting at the head
    {
        temp1->next = head;
        head = temp1;
        return;
    }
    Node* temp2 = head;
    for (int i = 0; i < n - 2; i++)
    {
        temp2 = temp2 -> next;
        n--;
    }

    temp1 -> next = temp2 -> next;
    temp2 -> next = temp1;
}

void Print()
{
    Node* ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr -> data);
        ptr = ptr -> next;
    }
}

int main()
{
    Insert(2, 1); // list : 2
    Insert(3, 2); // list : 2,3
    Insert(4, 1); // list : 4,2,3
    Insert(5, 2); // list : 4,5,2,3

    Print();

    return 0;
}
