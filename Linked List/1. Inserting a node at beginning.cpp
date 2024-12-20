#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

void Insert(Node** head, int x)
{
    Node* temp = new Node();
    temp -> data = x;

    if (*head != NULL) temp -> next = *head;
    else temp -> next = NULL;

    *head = temp;
}

void Print(Node* head)
{
    cout << "List is : ";
    while (head != NULL)
    {
        cout << head->data << ' ';
        head = head -> next;
    }
    cout << nl;
}

int main()
{
    Node* head = nullptr;
    int n, x;

    // why 'flush' ?

    /* Add std::cout << std::flush; or std::cout << std::endl;
    after the cout statement to force the output to appear before cin. */

    cout << "Enter number of input : " << flush;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter the number : " << flush;
        cin >> x;

        Insert(&head, x);
        Print(head);
    }

    return 0;
}
