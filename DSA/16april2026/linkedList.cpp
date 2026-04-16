// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class Node
{
public:
  int data;
  Node *next;
  Node(int value)
  {
    data = value;
    next = nullptr;
  }
};

int main()
{
  Node *head = new Node(1);
  head->next = new Node(2);
  head->next->next = new Node(3);
  Node *temp = head;

  while (temp->next != nullptr)
  {
    temp = temp->next;
  }
  temp->next = new Node(50);
  temp = head;
//------------------------------------------------
  // insert node at front
  Node *newNode = new Node(1000);
  newNode->next = head;
  head = newNode;

  temp = newNode;
  
  while (temp != nullptr)
  {
    cout << temp->data << " --> ";
    temp = temp->next;
  }
  cout << "NULL :) Added 1000 at front";
  cout << endl;
  cout << endl;
//------------------------------------------------
  temp = head;

  // insert in middle
  int given = 2;
  while (temp->next->data != given)
  {
    temp = temp->next;
  }
  Node *middlenode = new Node(100);
  middlenode->next = temp->next;
  temp->next = middlenode;
//------------------------------------------------
  temp = head;
  while (temp != nullptr)
  {
    cout << temp->data << " --> ";
    temp = temp->next;
  }
  cout << "NULL :) Inserted 100 before 2";
  cout << endl;
  cout << endl;
//------------------------------------------------
  temp = head;
  // deletion at last
  while (temp->next->next != nullptr)
  {
    temp = temp->next;
  }
  Node *delnode = temp->next; // just to delete the node (optional)
  delete delnode;
  temp->next = nullptr;

  temp = head;
  while (temp != nullptr)
  {
    cout << temp->data << " --> ";
    temp = temp->next;
  }
  cout << "NULL :) Last node gone";
  cout << endl;
  cout << endl;
//------------------------------------------------
  Node* delNode = head;
  // deletion at front

  head = head->next;
  temp = head;
  while(temp!=nullptr){
    cout<<temp->data<<" --> ";
    temp = temp->next;
  }
  cout<<"NULL :) Front node gone";
  cout<<endl;
  cout<<endl;
  delete delNode;

 //------------------------------------------------ 
  // adding a node at start for practice
  Node* newNode2 = new Node(10000);
  newNode2->next = head;
  head = newNode2;
  temp = head;
  while(temp!=nullptr){
    cout<<temp->data<<" --> ";
    temp = temp->next;
  }
  cout<<"NULL :) Added a node at start for practice";
  cout<<endl;
  cout<<endl;

//------------------------------------------------
  // Now deleting the 2nd node
  temp = head;
  head->next = head->next->next;
  while(temp!=nullptr){
    cout<<temp->data<<" --> ";
    temp = temp->next;
  }
  cout<<"NULL :) 2nd node gone";
  cout<<endl;
  cout<<endl;

  return 0;
}