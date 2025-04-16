#include "bits/stdc++.h"
using namespace std;

struct node {
  int data;
  node *next;
};

node *head;

void insertEnd(int data) {
  node *created = new node();
  created->data = data;

  if (head == NULL) {
    head = created;
    head->next = head;
    return;
  }

  node *tmp = head;
  while (tmp->next != head) {
    tmp = tmp->next;
  }

  tmp->next = created;
  created->next = head;
}

void printList() {
  // assuming head isn't empty

  // do..while because tmp == head
  node *tmp = head;
  do {
    cout << tmp->data << " -> ";
    tmp = tmp->next;
  } while (tmp != head);

  cout << "(head)\n"; // Indicate circular structure
}

// ###############
// # Golden rule #
// ###############
//
// Inspect tmp->next if you need the last address in a var
// otherwise tmp != NULL check will suffice

int main() {
  insertEnd(10);
  insertEnd(20);
  insertEnd(30);
  insertEnd(40);
  insertEnd(50);
  insertEnd(60);
  printList();
}
