#include<iostream>
#include<stack>
using namespace std;
// Last in first out -> Stack
// Make a stack using linked list.
//infix to postfix
// postfix evaluate
struct Node{
    int data;
    Node* next;
};

class Stack{
    private:
    Node* top; 
    public:
    Stack()
    {
        top = NULL;
    }

    bool isEmpty()
    {
        return top == NULL;
    }

    void push(int value)
    {
        // Overflow condition
        
        Node* newNode = new Node;
        newNode -> data = value;
        newNode -> next = top;
        top = newNode;
    }

    
    // pop 
    int pop(){
        if(isEmpty())
        {
            cout << "Stack is empty" << '\n';
            return -1;
        }

        int value = top -> data;
        Node* temp = top;
        top = top -> next;
        delete temp;
        return value;
    }
       void printStack() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        Node* temp = top;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    Stack s;
    s.push(10);
    s.printStack();
    s.push(20);
    s.printStack();
    s.push(30);
    s.printStack();
    cout << "Popped Value : " << s.pop() << '\n';
    s.printStack();
    return 0;


}