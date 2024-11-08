//homework
#include <iostream>
using namespace std;

class Deque {
private:
    int* arr;
    int front;
    int rear;
    int size;
    int capacity;

public:
    // Constructor to initialize the deque
    Deque(int capacity) {
        this->capacity = capacity;
        arr = new int[capacity];
        front = -1;
        rear = 0;
        size = 0;
    }

    // Function to check if the deque is full
    bool isFull() {
        return size == capacity;
    }

    // Function to check if the deque is empty
    bool isEmpty() {
        return size == 0;
    }

    // Function to insert an element at the front
    void insertFront(int element) {
        if (isFull()) {
            cout << "Deque is full!" << endl;
            return;
        }

        if (front == -1) {  // If deque is empty
            front = rear = 0;
        } else if (front == 0) {
            front = capacity - 1;  // Circular behavior
        } else {
            front--;
        }

        arr[front] = element;
        size++;
        cout << element << " inserted at front." << endl;
    }

    // Function to insert an element at the rear
    void insertRear(int element) {
        if (isFull()) {
            cout << "Deque is full!" << endl;
            return;
        }

        if (rear == -1) {  // If deque is empty
            front = rear = 0;
        } else if (rear == capacity - 1) {
            rear = 0;  // Circular behavior
        } else {
            rear++;
        }

        arr[rear] = element;
        size++;
        cout << element << " inserted at rear." << endl;
    }

    // Function to delete an element from the front
    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque is empty!" << endl;
            return;
        }

        cout << arr[front] << " deleted from front." << endl;

        if (front == rear) {  // If only one element is present
            front = rear = -1;
        } else if (front == capacity - 1) {
            front = 0;  // Circular behavior
        } else {
            front++;
        }

        size--;
    }

    // Function to delete an element from the rear
    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque is empty!" << endl;
            return;
        }

        cout << arr[rear] << " deleted from rear." << endl;

        if (front == rear) {  // If only one element is present
            front = rear = -1;
        } else if (rear == 0) {
            rear = capacity - 1;  // Circular behavior
        } else {
            rear--;
        }

        size--;
    }

    // Function to get the front element
    int getFront() {
        if (isEmpty()) {
            cout << "Deque is empty!" << endl;
            return -1;
        }
        return arr[front];
    }

    // Function to get the rear element
    int getRear() {
        if (isEmpty()) {
            cout << "Deque is empty!" << endl;
            return -1;
        }
        return arr[rear];
    }

    // Destructor to free allocated memory
    ~Deque() {
        delete[] arr;
    }
};

int main() {
    Deque dq(5);

    dq.insertRear(10);
    dq.insertRear(20);
    dq.insertFront(5);
    dq.insertFront(1);

    cout << "Front element: " << dq.getFront() << endl;
    cout << "Rear element: " << dq.getRear() << endl;

    dq.deleteFront();
    dq.deleteRear();

    cout << "Front element after deletion: " << dq.getFront() << endl;
    cout << "Rear element after deletion: " << dq.getRear() << endl;

    return 0;
}
