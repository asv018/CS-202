// circular queue using array
// insert delete and display
// circular queue implement using linked list 
#include <iostream>
using namespace std;

const int MAX_SIZE = 10; // maximum size of the queue

class CircularQueue {
    private:
        int front, rear;
        int queue[MAX_SIZE];
    public:
        CircularQueue() {
            front = -1;
            rear = -1;
        }

        bool is_empty() {
            return (front == -1 && rear == -1);
        }

        bool is_full() {
            return ((rear+1)%MAX_SIZE == front);
        }

        void enqueue(int val) {
            if (is_full()) {
                cout << "Queue is full\n";
                return;
            } else if (is_empty()) {
                front = 0;
                rear = 0;
            } else {
                rear = (rear+1)%MAX_SIZE;
            }
            queue[rear] = val;
        }

        void dequeue() {
            if (is_empty()) {
                cout << "Queue is empty\n";
                return;
            } else if (front == rear) {
                front = -1;
                rear = -1;
            } else {
                front = (front+1)%MAX_SIZE;
            }
        }

        int get_front() {
            if (is_empty()) {
                cout << "Queue is empty\n";
                return -1;
            } else {
                return queue[front];
            }
        }

        int get_rear() {
            if (is_empty()) {
                cout << "Queue is empty\n";
                return -1;
            } else {
                return queue[rear];
            }
        }

        void display() {
            if (is_empty()) {
                cout << "Queue is empty\n";
                return;
            }

            cout << "Current state of the queue: ";
            int i = front;
            while (i != rear) {
                cout << queue[i] << " ";
                i = (i+1)%MAX_SIZE;
            }
            cout << queue[rear] << endl;
        }
};

int main() {
    CircularQueue q;
    int choice, val;

    do {
        cout << "Enter your choice:\n1. Enqueue\n2. Dequeue\n3. Front element\n4. Rear element\n5. Display queue\n6. Exit\n";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to enqueue: ";
                cin >> val;
                q.enqueue(val);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                cout << "Front element: " << q.get_front() << endl;
                break;
            case 4:
                cout << "Rear element: " << q.get_rear() << endl;
                break;
            case 5:
                q.display();
                break;
            case 6:
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 6);

    return 0;
}
