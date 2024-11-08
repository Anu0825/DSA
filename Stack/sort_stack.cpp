#include<iostream>
#include<stack>
using namespace std;
void sortedInsert(stack<int> &inputStack,int num){  
    if(inputStack.empty()||(!inputStack.empty() && inputStack.top()<num)){
        inputStack.push(num);
        return;
    }
    int elem=inputStack.top();
    inputStack.pop();
    sortedInsert(inputStack,num);
    inputStack.push(elem);
}
void sortStack(stack<int> &inputStack){
    if(inputStack.empty()){
        return;
    }
    int num=inputStack.top();
    inputStack.pop();
    sortStack(inputStack);
    sortedInsert(inputStack,num);
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
    sortStack(inputStack);
    while(!inputStack.empty()){
        cout<<inputStack.top()<<" ";
        inputStack.pop();
    }
}