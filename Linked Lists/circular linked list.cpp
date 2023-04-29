//  Circular linked list
#include <iostream>

using namespace std;

struct Node {
  int data;
  struct Node* next;
};

struct Node* addToEmpty(struct Node* last, int data){

  if(last!=NULL) return last;

  // allocate memory to new node
  struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

  newNode->data = data;
  last = newNode;
  last->next = last;  // since list is empty. new node should be connected to itself;
  return last;
}

struct Node * addAtEnd(struct Node* last, int data){
  if(last==NULL) return addToEmpty(last, data);

  struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = last->next;
  last->next = newNode;
  return newNode; // rreturn last node

}
void transverse(struct Node *last){

  struct Node *current;
  current = last->next;
  do {
    cout << current->data << " ";
    current = current->next;
  }while(current!= last->next);
  cout << endl;
}

int main(){
  struct Node* last = NULL;

  last = addToEmpty(last, 1);
  last = addAtEnd(last, 2);
  last = addAtEnd(last, 3);
  last = addAtEnd(last, 4);
  transverse(last);

};