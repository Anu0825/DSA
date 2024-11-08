#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Queue class
class Queue {
private:
    Node* front;
    Node* rear;

public:
    // Constructor to initialize the queue
    Queue() {
        front = rear = nullptr;
    }

    // Function to add an element to the queue
    void enqueue(int value) {
        Node* temp = new Node(value);
        if (rear == nullptr) {
            // If queue is empty, front and rear are the same
            front = rear = temp;
            cout << value << " enqueued to the queue." << endl;
            return;
        }
        // Add the new node at the end and change the rear
        rear->next = temp;
        rear = temp;
        cout << value << " enqueued to the queue." << endl;
    }

    // Function to remove an element from the queue
    int dequeue() {
        if (front == nullptr) {
            // If the queue is empty
            cout << "Queue is empty!" << endl;
            return -1;
        }
        // Store the previous front and move the front pointer
        Node* temp = front;
        front = front->next;

        // If the queue becomes empty, set rear to nullptr
        if (front == nullptr)
            rear = nullptr;

        int dequeuedValue = temp->data;
        delete temp;  // Free the memory of the dequeued node
        return dequeuedValue;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Function to get the front element of the queue
    int peekFront() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return front->data;
    }

    // Destructor to free the memory
    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << q.dequeue() << " dequeued from the queue." << endl;
    cout << "Front element is: " << q.peekFront() << endl;

    q.enqueue(40);
    cout << q.dequeue() << " dequeued from the queue." << endl;

    return 0;
}