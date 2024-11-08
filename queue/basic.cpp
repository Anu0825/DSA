// queue follows FIFO (first in first out)
// when we do pop op. always first element will pop out.
//q.front() will give the top elem of queue
#include<iostream>
#include<queue>
using namespace std;
int main(){
    queue<int> q;
    q.push(11);
    cout<<"front of queue is: "<<q.front()<<endl;
    q.push(12);
    cout<<"front of queue is: "<<q.front()<<endl;
    q.push(15);
    cout<<"front of queue is: "<<q.front()<<endl;

    cout<<"size of queue is: "<<q.size()<<endl;
    q.pop();
    q.pop();
    q.pop();
    cout<<"size of queue is: "<<q.size()<<endl;
    if(q.empty()){
        cout<<"queue is empty"<<endl;
    }
    else{
        cout<<"queue is not empty"<<endl;
    }
}