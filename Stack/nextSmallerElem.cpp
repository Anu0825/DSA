//given an array nd we have to make a new array in which at sme index just next smaller elem is present
//if not present then -1
//eg. {2,1,4,3} -> {1,-1,3,-1}
//1st approach by using 1st loop for elem nd sec loop for comp. with next elem. -> time comp O(n2)
//another approach using stacks -> time comp -> O(n)
#include<iostream>
#include<stack>
using namespace std;
int main(){
    int n;
    cout<<"enter size:";
    cin>>n;
    int *arr=new int[n];
    cout<<"enter array elements:"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int *ans=new int[n];
    stack<int> st;
    st.push(-1);
    for(int i=n-1;i>=0;i--){
        while(st.top()>=arr[i]){
            st.pop();
        }
        ans[i]=st.top();
        st.push(arr[i]);
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
}