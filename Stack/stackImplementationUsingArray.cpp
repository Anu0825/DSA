#include<iostream>
using namespace std;
class Stack{
    //properties
    public:
    int size;
    int *arr;
    int top;
    // behaviour
    Stack(int size){
        this -> size=size;
        arr=new int[size];
        top=-1;
    }
    void push(int element){
        if((size-top)>1){
            top++;
            arr[top]=element;
        }
        else{
            cout<<"stack overflow"<<endl;
        }
    }
    void pop(){
        if (top>=0){
            top--;
        }
        else{
            cout<<"stack underflow"<<endl;
        }
    }
    int peek(){
        if(top>=0){
            return arr[top];
        }
        else{
            cout<<"stack is empty"<<endl;
            return -1;
        }
    }
    bool isEmpty(){
        if (top==-1){
            return true;
        }
        else{
            return false;
        }
    }

};
int main(){
    Stack st(5);
    st.push(22);
    st.push(43);
    st.push(44);

    cout<<"top elem:"<<st.peek()<<endl;
    st.pop();
    cout<<"after pop top elem:"<<st.peek()<<endl;
}
/*
#include <iostream>
using namespace std;

class Stack {
private:
    int top;
    int arr[100];  // Array to hold stack elements
    int maxSize;

public:
    Stack(int size = 100) {  // Constructor to initialize the stack
        maxSize = size;
        top = -1;  // Stack is initially empty
    }

    // Function to push an element onto the stack
    void push(int x) {
        if (top >= maxSize - 1) {
            cout << "Stack overflow, cannot push " << x << endl;
        } else {
            arr[++top] = x;
            cout << x << " pushed into the stack" << endl;
        }
    }

    // Function to pop an element from the stack
    void pop() {
        if (top < 0) {
            cout << "Stack underflow, no elements to pop" << endl;
        } else {
            cout << arr[top--] << " popped from the stack" << endl;
        }
    }

    // Function to get the top element of the stack
    int peek() {
        if (top < 0) {
            cout << "Stack is empty" << endl;
            return -1;
        } else {
            return arr[top];
        }
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return (top < 0);
    }

    // Function to display the stack elements
    void display() {
        if (top < 0) {
            cout << "Stack is empty" << endl;
        } else {
            cout << "Stack elements are: ";
            for (int i = 0; i <= top; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Stack s(5);  // Create a stack of size 5

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);  // Will show stack overflow

    s.display();

    s.pop();
    s.pop();

    s.display();

    cout << "Top element is: " << s.peek() << endl;

    return 0;
}
*/