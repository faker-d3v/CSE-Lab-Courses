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
    return;
  }

  node *tmp = head;
  while (tmp->next) { // NULL == 0 == false :)
    tmp = tmp->next;
  }

  tmp->next = created;
}

void printList() {
  // assuming head isn't empty
  node *tmp = head;
  while (tmp != NULL) {
    cout << "current: " << tmp << endl;
    cout << "data   : " << tmp->data << endl;
    cout << "next   : " << tmp->next << endl << endl;
    tmp = tmp->next;
  }
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
