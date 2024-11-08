#include<iostream>
#include<queue>
#include<stack>
using namespace std;
void reverse_recursion(queue<int> &q,int n){
    if(q.empty()){                                // time comp. -> O(n)
        return;                                   // space comp. -> O(n)
    }
    int num=q.front();
    q.pop();
    reverse_recursion(q,n);
    q.push(num);
}
void reverseUsingStack(queue<int> &q,int n){            // time comp. -> O(n)
    stack<int> st;                                      // space comp. -> O(n)
    while(!q.empty()){                                  // stack has a property to reverse the elem.
        int num=q.front();
        st.push(num);
        q.pop();
    }
    while(!st.empty()){
        int num=st.top();
        q.push(num);
        st.pop();
    }
}
int main(){
    queue<int> q;
    int size;
    cout<<"enter size:";
    cin>>size;
    for(int i=1;i<=size;i++){
        int x;
        cin>>x;
        q.push(x);
    }
    //reverse_recursion(q,size);
    reverseUsingStack(q,size);
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
}