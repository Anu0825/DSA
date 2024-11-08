// reverse first k elements of queue
#include<iostream>
#include<queue>
#include<stack>
using namespace std;
void reverseUsingStack(queue<int> &q,int n,int k){         
    stack<int> st;                                  // time comp. -> O(n)
    int cnt=0;                                      // space comp. -> O(k)
    while(cnt!=k){                                 
        int num=q.front();
        st.push(num);
        q.pop();
        cnt++;
    }
    while(!st.empty()){
        int num=st.top();
        q.push(num);
        st.pop();
    }
    cnt=0;
    while(cnt!=(n-k)){
        int num=q.front();
        q.pop();
        q.push(num);
        cnt++;
    }
}
int main(){
    queue<int> q;
    int size,k;
    cout<<"enter k:";
    cin>>k;
    cout<<"enter size:";
    cin>>size;
    for(int i=1;i<=size;i++){
        int x;
        cin>>x;
        q.push(x);
    }
    reverseUsingStack(q,size,k);
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
}