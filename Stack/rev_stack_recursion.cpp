// time comp -> O(n^2)
// space comp -> O(n)
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
void revStack(stack<int> &inputStack){
    if(inputStack.empty()){
        return;
    }
    int num=inputStack.top();
    inputStack.pop();
    revStack(inputStack);
    InsertAtBottom(inputStack,num);
}
int main(){
    stack<int> inputStack;
    int size;
    cout<<"enter size:";
    cin>>size;
    for(int i=1;i<=size;i++){
        int x;
        cin>>x;
        inputStack.push(x);
    }
    revStack(inputStack);
    while(!inputStack.empty()){
        cout<<inputStack.top()<<" ";
        inputStack.pop();
    }
}