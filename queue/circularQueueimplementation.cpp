#include<iostream>
using namespace std;
class CircularQueue{
    public:
    int *arr;
    int front;
    int rear;
    int size;
    CircularQueue(int size){
        this -> size=size;
        arr=new int[size];
        front=-1;
        rear=-1;
    }
    void enqueue(int data){
        if ((front==0 && rear==size-1)||(rear==(front-1)%(size-1))){
            cout<<"queue is full"<<endl;
        }
        else if(front==-1){  //first elem to push
            front=rear=0;
        }
        else if(rear==size-1 && front!=0){
            rear=0; //to maintain cyclic nature
        }
        else{
            //normal flow
            rear++;
        }
        //push inside the queue
        arr[rear]=data;
    }
    int dequeue(){ 
        if (front==-1){   //to check queue is empty
            return -1;
        }
        int ans=arr[front];
        arr[front]=-1;
        if(front==rear){  //single elem is present
            front=rear=-1;
        }
        else if(front==size-1){
            front=0; //to maintain cyclic nature
        }
        else{
            //normal flow
            front++;
        }
        return ans;
    }
};
int main(){
    CircularQueue q(3);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.dequeue();
    return 0;
}