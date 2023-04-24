
#include <iostream>

using namespace std;

// Linked list
// head -> A -> B -> C -> D -> NULL

struct ListNode
{
    int data;
    ListNode *next; // pointer
};

class linkedlist
{
private:
    ListNode *head;

public:
    linkedlist()
    {
        head = NULL;
    }

    void addElementFirst(int d);
    void addElementEnd(int d);
    void addElementAfter(int d, int b);
    void deleteElement(int d);
    void display();
    int length();
};

void linkedlist::addElementFirst(int d)
{
    ListNode *newNode = new ListNode;
    newNode->data = d;
    newNode->next = head;
    head = newNode;
}

void linkedlist::addElementEnd(int x)
{
    ListNode *newNode = new ListNode;
    ListNode *temp = new ListNode;
    temp = head;
    newNode->data = x;
    if (temp == NULL)
    {
        newNode->next = NULL;
        head = newNode;
        return;
    }

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    newNode->next = NULL;
    temp->next = newNode;
}

void linkedlist::addElementAfter(int d, int key)
{
    ListNode *search = new ListNode;
    search = head;
    while (search != NULL)
    {
        if (search->data == d)
        {
            ListNode *newNode = new ListNode;
            newNode->data = key;
            newNode->next = search->next;
            search->next = newNode;
            return;
        }
        search = search->next;
    }
    if (search == NULL)
        cout << "The link not inserted because there is not found the ListNode " << d << " in the LinkedList. " << endl;
}

void linkedlist::deleteElement(int d)
{
    ListNode *del;
    del = head;

    if (del == NULL)
    {
        cout << "Linked list is empty" << endl;
        return;
    }

    if (del->data == d)
    {
        head = del->next;
        return;
    }

    if (del->next == NULL)
    {
        cout << "Is not here, So not deleted." << endl;
        return;
    }

    while (del->next != NULL)
    {
        if (del->next->data == d)
        {
            del->next = del->next->next;
            return;
        }
        del = del->next;
    }
    cout << "Is not here, So not deleted." << endl;
}

int linkedlist::length()
{
    ListNode *curr = head;
    int n = 0;
    while (curr != NULL)
    {
        n++;
        curr = curr->next;
    }
    return n;
}

void linkedlist::display()
{
    ListNode *current = head;

    if (current == NULL)
    {
        cout << "\nThis is empty linked list.\n"
             << endl;
        return;
    }

    while (current != NULL)
    {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "NULL"
         << endl;
}

int main()
{
    linkedlist li;
    li.display();

    li.addElementFirst(25);
    li.addElementFirst(36);
    li.addElementFirst(49);
    li.addElementFirst(64);
    cout << "After adding in the first of linked list"
         << endl;
    li.display();
    cout << "LENGTH = " << li.length() << endl
         << endl;

    cout << "After adding in the end of linked list" << endl;
    li.addElementEnd(25);
    li.addElementEnd(36);
    li.addElementEnd(49);
    li.addElementEnd(64);
    li.display();
    cout << "LENGTH = " << li.length() << endl
         << endl;
    // head->64->49->36->25->25->36->49->64->NULL

    cout << "linked list after adding 10 after ListNode that has data = 49" << endl;
    li.addElementAfter(49, 10);
    li.display();
    cout << "LENGTH = " << li.length() << endl
         << endl;
    // head->64->49->10->36->25->25->36->49->64->NULL

    cout << "linked list after adding deleting 49" << endl;
    li.deleteElement(49);
    li.display();
    cout << "LENGTH = " << li.length() << endl
         << endl;
    // head->64->10->36->25->25->36->49->64->NULL
    // Notice :delete the first 49 ... not permission for duplicates

    // for(int i=0; li.size() ;++i)
    // {
    // if(li.deleteElement(49))
    //         li.display();
    // }

    return 0;
}