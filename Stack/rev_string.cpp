//time comp -> O(n) nd space comp O(n)
// better approach -> by swapping
#include<iostream>
#include<stack>
using namespace std;
int main(){
    string str,ans="";
    cout<<"enter string:";
    cin>>str;
    stack<char> s;
    for(int i=0;i<str.length();i++){
        s.push(str[i]);
    }
    while(!s.empty()){
        char ch=s.top();
        ans.push_back(ch);
        s.pop();
    }
    cout<<"reverse string is: "<<ans<<endl;
}
