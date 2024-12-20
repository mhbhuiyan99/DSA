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

void Delete(int n)
{
	Node* temp = head;

	if (n == 1)
	{
		head = temp -> next;
		delete (temp);
		return;
	}

	for (int i = 0; i < n - 2; i++)
		temp = temp -> next;

	Node* ptr = temp -> next;
	temp -> next = ptr -> next;

	delete ptr;
}

int main()
{
	Insert(2);
	Insert(4);
	Insert(6);
	Insert(5); // List : 2 4 6 5

	Print();
	Delete(3);
	Print();

	return 0;
}
