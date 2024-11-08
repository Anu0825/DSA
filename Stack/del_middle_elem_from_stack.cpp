#include<iostream>
#include<stack>
using namespace std;
void DelMiddle(stack<int> &inputStack,int size,int count){
    if(count==size/2){
        inputStack.pop();
        return;
    }
    int num=inputStack.top();
    inputStack.pop();
    DelMiddle(inputStack,size,count+1);
    inputStack.push(num);
}
int main(){
    stack<int> inputStack;
    int size,elem;
    cout<<"enter size:";
    cin>>size;
    for(int i=1;i<=size;i++){
        cin>>elem;
        inputStack.push(elem);
    }
    DelMiddle(inputStack,size,0);
    while(!inputStack.empty()){
        cout<<inputStack.top()<<" ";
        inputStack.pop();
    }
}