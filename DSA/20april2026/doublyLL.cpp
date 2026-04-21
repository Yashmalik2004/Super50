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

class doublyLinkedList
{
private:
  Node *head;
  Node *tail;

public:
  Node *tail;
  doublyLinkedList()
  {
    head = nullptr;
    tail = nullptr;
  }
  void insertAtEnd(int value)
  {
    Node *newNode = new Node(value);

    if (tail == nullptr)
    {
      head = tail = newNode;
    }
    else
    {
      tail->next = newNode;
      newNode->prev = tail;
      tail = newNode;
    }
    cout << "Inserted at end: " << value << endl;
  }

  void insertAtFront(int value)
  {
    Node *newNode = new Node(value);

    if (head == nullptr)
    {
      head = tail = newNode;
    }
    else
    {
      newNode->next = head;
      head->prev = newNode;
      head = newNode;
    }
    cout << "Inserted at front: " << value << endl;
  }
  void display()
  {
    Node *temp = head;
    while (temp != nullptr)
    {
      cout << temp->data << " ";
      temp = temp->next;
    }
  }

  void deleteFromEnd()
  {
    if (tail == nullptr)
    {
      cout << "Empty list, nothing to delete." << endl;
      return;
    }
    if (tail->prev = nullptr)
    {
      delete tail;
      head = tail = nullptr;
      cout << "Deleted from end, now the list if totally empty." << endl;
    }
    Node *temp = tail;
    tail = tail->prev;
    temp->next = nullptr;
    delete temp;
    cout << "Deleted from end." << endl;
  }
  void deleteFromFront()
  {
    if (head == nullptr)
    {
      cout << "Empty list, nothing to delete." << endl;
      return;
    }
    if (head->next == nullptr)
    {
      delete head;
      head = tail = nullptr;
      cout << "Deleted from front, now the list if totally empty." << endl;
      return;
    }
    Node *temp = head;
    head = head->next;
    head->prev = nullptr;
    delete temp;
    cout << "Deleted from front." << endl;
  }
  void insertAtPosition(int value, int position)
  {
    if (position < 1)
    {
      cout << "Invalid position." << endl;
      return;
    }

    // Case 1: Insert at front
    if (position == 1)
    {
      insertAtFront(value);
      return;
    }

    Node *temp = head;
    int count = 1;

    // Traverse to (position - 1) node
    while (temp != nullptr && count < position - 1)
    {
      temp = temp->next;
      count++;
    }

    // If position is out of bounds
    if (temp == nullptr)
    {
      cout << "Position out of range." << endl;
      return;
    }

    // Case 2: Insert at end
    if (temp->next == nullptr)
    {
      insertAtEnd(value);
      return;
    }

    // Case 3: Insert in middle
    Node *newNode = new Node(value);

    newNode->next = temp->next;
    newNode->prev = temp;

    temp->next->prev = newNode;
    temp->next = newNode;

    cout << "Inserted at position " << position << endl;
  }
};

int main()
{

  // Iterating the DLL
  // temp = head;
  while (temp != nullptr)
  {
    cout << temp->data << " ";
    temp = temp->next;
  }
  return 0;
}