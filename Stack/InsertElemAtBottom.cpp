//insert an element at the bottom of the stack
#include<iostream>
#include<stack>
using namespace std;
void InsertAtBottom(stack<int> &inputStack,int elem){
    if(inputStack.empty()){
        inputStack.push(elem);
        return;
    }
    int num=inputStack.top();
    inputStack.pop();
    InsertAtBottom(inputStack,elem);
    inputStack.push(num);
}
int main(){
    stack<int> inputStack;
    int size,element;
    cout<<"enter size:";
    cin>>size;
    cout<<"enter element:";
    cin>>element;
    for(int i=1;i<=size;i++){
        int x;
        cin>>x;
        inputStack.push(x);
    }
    InsertAtBottom(inputStack,element);
    while(!inputStack.empty()){
        cout<<inputStack.top()<<" ";
        inputStack.pop();
    }
}