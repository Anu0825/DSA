// we can implement heap using priority queue also
#include<iostream>
#include<queue>
using namespace std;
int main(){
    //max heap
    priority_queue<int> maxHeap;
    maxHeap.push(4);
    maxHeap.push(2);
    maxHeap.push(5);
    maxHeap.push(3);
    cout<<"element at top "<<maxHeap.top()<<endl;
    maxHeap.pop();
    cout<<"element at top "<<maxHeap.top()<<endl;
    cout<<"size is "<<maxHeap.size()<<endl;
    if(maxHeap.empty()){
        cout<<"max heap is empty"<<endl;
    }
    else{
        cout<<"max heap is not empty"<<endl;
    }

    //min heap
    priority_queue<int,vector<int>,greater<int>> minHeap;
    minHeap.push(4);
    minHeap.push(2);
    minHeap.push(5);
    minHeap.push(3);
    cout<<"element at top "<<minHeap.top()<<endl;
    minHeap.pop();
    cout<<"element at top "<<minHeap.top()<<endl;
    cout<<"size is "<<minHeap.size()<<endl;
    if(minHeap.empty()){
        cout<<"min heap is empty"<<endl;
    }
    else{
        cout<<"min heap is not empty"<<endl;
    }
    return 0;
}