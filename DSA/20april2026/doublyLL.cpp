#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  int data;
  Node *next;
  Node *prev;

  Node(int value)
  {
    data = value;
    next = nullptr;
    prev = nullptr;
  }
};

int main()
{

  Node *head = new Node(10);
  Node *tail = head;
  // Insert at front
  Node *fnode = new Node(5);
  fnode->next = head;
  head->prev = fnode;
  head = fnode;

  // Insert at last
  Node *lnode = new Node(15);
  tail->next = lnode;
  lnode->prev = tail;
  tail = lnode;

  // Iterating the DLL
  Node *temp = head;
  while (temp != nullptr)
  {
    cout << temp->data << " ";
    temp = temp->next;
  }
  return 0;
}