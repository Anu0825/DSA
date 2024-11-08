#include<iostream>
using namespace std;
class Queue{
    public:
      int *arr;
      int front;
      int rear;
      int size;
      Queue(int size){
        this -> size=size;
        arr=new int[size];
        front=0;
        rear=0;
      }
      bool isEmpty(){
        if (front==rear){
            return true;
        }
        else{
            return false;
        }
      }
      // to insert/ push the element
      void enqueue(int data){
        if(rear==size){
            cout<<"Queue is full"<<endl;
        }
        else{
            arr[rear]=data;
            rear++;
        }
      }
      // to pop an element
      int dequeue(){
        if(rear==front){
            return -1;
        }
        else{
            int ans=arr[front];
            arr[front]=-1;
            front++;
            if(front==rear){
                front=0;
                rear=0;
            }
            return ans;
        }
      }
      // top element
      int top(){
        if(front==rear){
            return -1;
        }
        else{
            return arr[front];
        }
      }

};
int main(){
    Queue q(6);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout<<"top elem: "<<q.top()<<endl;
    q.dequeue();
    cout<<"top elem: "<<q.top()<<endl;
    cout<<"queue is empty -> "<<q.isEmpty()<<endl;
}
/*
#include <iostream>
using namespace std;

class Queue {
private:
    int* arr;      // Array to store queue elements
    int front;     // Front points to the front element in the queue
    int rear;      // Rear points to the last element in the queue
    int capacity;  // Maximum capacity of the queue
    int count;     // Current size of the queue

public:
    // Constructor to initialize the queue
    Queue(int size) {
        arr = new int[size];
        capacity = size;
        front = 0;
        rear = -1;
        count = 0;
    }

    // Destructor to free memory allocated for the array
    ~Queue() {
        delete[] arr;
    }

    // Function to add an element to the queue (enqueue)
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue overflow" << endl;
            return;
        }

        rear = (rear + 1) % capacity;  // Circular increment
        arr[rear] = value;
        count++;
    }

    // Function to remove an element from the queue (dequeue)
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue underflow" << endl;
            return -1;
        }

        int item = arr[front];
        front = (front + 1) % capacity;  // Circular increment
        count--;
        return item;
    }

    // Function to return the front element of the queue
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return count == 0;
    }

    // Function to check if the queue is full
    bool isFull() {
        return count == capacity;
    }

    // Function to return the current size of the queue
    int size() {
        return count;
    }

    // Function to display the elements of the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }

        for (int i = 0; i < count; i++) {
            cout << arr[(front + i) % capacity] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q(5);

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

*/