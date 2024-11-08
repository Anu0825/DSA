//stack follows LIFO (last in first out)
#include<iostream>
#include<stack>
using namespace std;
int main(){
    // creation of stack
    stack<int> s;
    //push operation
    s.push(1);
    s.push(2);
    s.push(3);
    //pop
    s.pop();
    cout<<"printing top elem: "<<s.top()<<endl;
    if(s.empty()){
        cout<<"stack is empty"<<endl;
    }
    else{
        cout<<"stack is not empty"<<endl;
    }
    cout<<"size of stack: "<<s.size()<<endl;
    //does not work on stacks we cant iterator through loops
    /*for(auto i:s){
        cout<<i<<" ";
    }*/
   while(!s.empty()){
    cout<<s.top()<<" ";
    s.pop();
   }
}