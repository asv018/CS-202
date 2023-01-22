#include <iostream>

using namespace std;

struct Node {
  int data;
  Node* next;
};

Node* head = NULL;

void insertAtHead(int data) {
  Node* newNode = new Node();
  newNode->data = data;
  newNode->next = head;
  head = newNode;
}

void insertAtTail(int data) {
  Node* newNode = new Node();
  newNode->data = data;
  newNode->next = NULL;
  
  if (head == NULL) {
    head = newNode;
    return;
  }

  Node* temp = head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = newNode;
}

void insertAtPosition(int data, int position) {
  if (position == 1) {
    insertAtHead(data);
    return;
  }

  Node* newNode = new Node();
  newNode->data = data;

  Node* temp = head;
  for (int i = 0; i < position - 2; i++) {
    temp = temp->next;
  }
  newNode->next = temp->next;
  temp->next = newNode;
}

void deleteAtHead() {
  if (head == NULL) {
    return;
  }

  Node* temp = head;
  head = head->next;
  delete temp;
}

void deleteAtTail() {
  if (head == NULL) {
    return;
  }

  if (head->next == NULL) {
    delete head;
    head = NULL;
    return;
  }

  Node* temp = head;
  while (temp->next->next != NULL) {
    temp = temp->next;
  }
  delete temp->next;
  temp->next = NULL;
}

void deleteAtPosition(int position) {
  if (head == NULL) {
    return;
  }

  if (position == 1) {
    deleteAtHead();
    return;
  }

  Node* temp = head;
  for (int i = 0; i < position - 2; i++) {
    temp = temp->next;
  }
  Node* nodeToDelete = temp->next;
  temp->next = nodeToDelete->next;
  delete nodeToDelete;
}

void printList() {
  Node* temp = head;
  while (temp != NULL) {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}

int main() {
  insertAtHead(5);
  insertAtHead(10);
  insertAtHead(15);
  cout << "List after inserting at head: ";
  printList();

  insertAtTail(20);
  insertAtTail(25);
  cout << "List after inserting at tail: ";
  printList();

  insertAtPosition(30, 3);
  cout << "List after inserting at position 3: ";
  printList();

  deleteAtHead();
  cout << "List after deleting at head
