#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        next = nullptr;
    }
};

class CircularQueue {
private:
    Node* front;
    Node* rear;
    int size;
    int capacity;
public:
    CircularQueue(int capacity) {
        front = nullptr;
        rear = nullptr;
        size = 0;
        this->capacity = capacity;
    }
    bool isFull() {
        return size == capacity;
    }
    bool isEmpty() {
        return size == 0;
    }
    void enqueue(int data) {
        if (isFull()) {
            cout << "Queue is full\n";
            return;
        }
        Node* newNode = new Node(data);
        if (isEmpty()) {
            front = newNode;
        }
        else {
            rear->next = newNode;
        }
        rear = newNode;
        rear->next = front;
        size++;
    }
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        Node* temp = front;
        if (front == rear) {
            front = nullptr;
            rear = nullptr;
        }
        else {
            front = front->next;
            rear->next = front;
        }
        delete temp;
        size--;
    }
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        Node* temp = front;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != front);
        cout << endl;
    }
};

int main() {
    int capacity;
    cout << "Enter capacity of circular queue: ";
    cin >> capacity;
    CircularQueue q(capacity);
    int choice, data;
    while (true) {
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter data to enqueue: ";
            cin >> data;
            q.enqueue(data);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.display();
            break;
        case 4:
            exit(0);    
        default:
            cout << "Invalid choice" << '\n';
        }
    }
    return 0;
}
