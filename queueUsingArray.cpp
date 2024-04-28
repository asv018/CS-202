#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

class Queue
{
private:
    int front, rear, size;
    int arr[MAX_SIZE];

public:
    Queue()
    {
        front = -1;
        rear = -1;
        size = 0;
    }

    bool isEmpty()
    {
        return front == -1 && rear == -1;
    }

    bool isFull()
    {
        return (rear + 1) % MAX_SIZE == front;
    }

    int getSize()
    {
        return size;
    }

    void enqueue(int data)
    {
        if (isFull())
        {
            cout << "Queue is full" << endl;
            return;
        }

        if (isEmpty())
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % MAX_SIZE;
        }

        arr[rear] = data;
        size++;
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return INT16_MIN;
        }

        int data = arr[front];
        size--;

        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % MAX_SIZE;
        }

        return data;
    }
};
