
#include <iostream>

using namespace std;

// Doubly Linked List
// NULL <=> A <=> B <=> C <=> D <=> NULL

struct DListNode
{
    int data;
    DListNode *prev; // pointer
    DListNode *next; // pointer
};

class doublelinkedlist
{
private:
    DListNode *head;

public:
    doublelinkedlist()
    {
        head = NULL;
    }

    void display();
    void insertAtBegining(int value);
    void insertAtEnd(int value);
    void insertAtIndex(int value, int index);
    void deleteNode(int index);
};
void doublelinkedlist::display()
{
    DListNode *current = head;

    cout << "NULL<=>"<< current->data << "<=>";
    do
    {
        current = current->next;
        cout << current->data << "<=>";
    } while (current->next != NULL);
    cout <<"NULL"<< endl;
}

void doublelinkedlist::insertAtBegining(int d)
{
    DListNode *newNode = new DListNode;
    newNode->prev = NULL;
    newNode->data = d;
    newNode->next = head;

    head = newNode;
}

void doublelinkedlist::insertAtEnd(int d){
    DListNode *newNode = new DListNode;
    newNode->prev = NULL;
    newNode->data = d;
    newNode->next = NULL;

    DListNode *current = head;

    while(current->next != NULL){
        current = current->next;
    }
    newNode->prev = current;
    current->next = newNode;
}

void doublelinkedlist::insertAtIndex(int d, int index){
    DListNode *newNode = new DListNode;
    newNode->prev = NULL;
    newNode->data = d;
    newNode->next = NULL;

    DListNode *current = head;

    for(int i=1;i<index;i++){
        current = current->next;
    }
    // ptr → next = temp → next; 
    // ptr → prev = temp;
    // temp → next = ptr;  
    // temp → next → prev = ptr;  
    newNode->next = current->next;
    newNode->prev = current;
    current->next = newNode;
    current->next->prev = newNode;

}

int main()
{
    doublelinkedlist dli;
    dli.insertAtBegining(5);
    dli.insertAtBegining(4);
    dli.insertAtBegining(3);
    dli.insertAtBegining(2);
    dli.insertAtBegining(1);
    dli.display();
    dli.insertAtIndex(10,1);
    dli.display();
    dli.insertAtEnd(20);
    dli.display();
    return 0;
}