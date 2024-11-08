#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    
    Node(int value) : data(value), next(nullptr) {}
};

// Queue class using linked list
class Queue {
private:
    Node* front;
    Node* rear;
    
public:
    Queue() : front(nullptr), rear(nullptr) {}

    // Enqueue (insert) an element into the queue
    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (rear == nullptr) {
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }

    // Dequeue (remove) an element from the queue
    int dequeue() {
        if (front == nullptr) {
            cout << "Queue underflow" << endl;
            return -1;
        }
        Node* temp = front;
        int dequeuedValue = temp->data;
        front = front->next;

        if (front == nullptr) {
            rear = nullptr;  // If queue becomes empty
        }

        delete temp;
        return dequeuedValue;
    }

    // Peek the front element of the queue
    int peek() {
        if (front == nullptr) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return front->data;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Display the queue elements
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        Node* current = front;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    cout << "Queue elements: ";
    q.display();

    cout << "Dequeued element: " << q.dequeue() << endl;
    cout << "Queue after dequeue: ";
    q.display();

    cout << "Front element: " << q.peek() << endl;

    return 0;
}
