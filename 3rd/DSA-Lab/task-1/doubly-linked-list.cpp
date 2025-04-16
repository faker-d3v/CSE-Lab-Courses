#include <bits/stdc++.h>
using namespace std;

struct node {
  node *prev;
  int data;
  node *next;
};

node *head;

void createNode(int value) {
  node *created = new node();
  created->data = value;

  if (head == NULL) {
    head = created;
    return;
  }

  node *tmp = head;
  while (tmp->next != NULL) {
    tmp = tmp->next;
  }

  tmp->next = created;
  created->prev = tmp;
}

void printNodes() {
  if (head == NULL) {
    cout << "The list is empty." << endl;
    return;
  }
  node *tmp = head;
  while (tmp != NULL) {
    cout << "[address " << tmp << "]" << endl;
    cout << "prev   : " << tmp->prev << endl;
    cout << "data   : " << tmp->data << endl;
    cout << "next   : " << tmp->next << endl << endl;
    tmp = tmp->next;
  }
}

int main() {
  createNode(10);
  createNode(20);
  createNode(30);
  createNode(40);
  createNode(50);
  printNodes();
}
