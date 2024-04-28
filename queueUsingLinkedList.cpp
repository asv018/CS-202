#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class Queue
{
private:
    Node *head;
    Node *tail;

public:
    Queue()
    {
        head = NULL;
        tail = NULL;
    }

    bool isEmpty()
    {
        return head == NULL;
    }

    void enqueue(int data)
    {
        Node *temp = new Node();
        temp->data = data;
        temp->next = NULL;

        if (tail == NULL)
        {
            head = tail = temp;
            return;
        }

        tail->next = temp;
        tail = temp;
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return INT16_MIN;
        }

        Node *temp = head;
        int data = temp->data;
        head = head->next;

        if (head == NULL)
        {
            tail = NULL;
        }

        delete temp;
        return data;
    }
};
