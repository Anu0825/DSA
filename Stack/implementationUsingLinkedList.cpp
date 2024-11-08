#include <iostream>
using namespace std;

// Define the structure of a node
struct Node {
    int data;
    Node* next;
};

// Stack class using a linked list
class Stack {
private:
    Node* top; // Pointer to the top of the stack

public:
    // Constructor to initialize the stack
    Stack() {
        top = nullptr; // Initially, the stack is empty
    }

    // Function to push an element onto the stack
    void push(int value) {
        Node* newNode = new Node(); // Create a new node
        newNode->data = value;      // Set the value for the new node
        newNode->next = top;        // Make the new node point to the current top
        top = newNode;              // Update the top to the new node
        cout << value << " pushed onto stack\n";
    }

    // Function to pop an element from the stack
    void pop() {
        if (top == nullptr) {
            cout << "Stack is empty. Cannot pop.\n";
            return;
        }
        Node* temp = top;  // Temporarily store the top node
        top = top->next;   // Move the top to the next node
        cout << temp->data << " popped from stack\n";
        delete temp;       // Delete the old top node
    }

    // Function to return the top element of the stack
    int peek() {
        if (top == nullptr) {
            cout << "Stack is empty.\n";
            return -1; // Return -1 if the stack is empty
        }
        return top->data; // Return the data of the top node
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return top == nullptr;
    }

    // Destructor to free the memory when the stack is destroyed
    ~Stack() {
        while (top != nullptr) {
            pop();
        }
    }
};

// Main function to demonstrate stack operations
int main() {
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Top element is: " << stack.peek() << endl;

    stack.pop();
    stack.pop();

    cout << "Top element is: " << stack.peek() << endl;

    stack.pop();

    // Check if the stack is empty
    if (stack.isEmpty()) {
        cout << "Stack is empty now.\n";
    }

    return 0;
}
