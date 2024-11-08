//given a string we have to always return first non repeating elem. else #
// eg. "aabcdbcc" -> "a#bbbcdd"
#include<bits/stdc++.h>
using namespace std;
string firstNonRep(string exp){
    map<char,int> m;
    string ans="";
    queue<char> q;
    for(int i=0;i<exp.length();i++){
        char ch=exp[i];
        q.push(ch);
        m[ch]++;
        while(!q.empty()){
            if(m[q.front()]>1){
                q.pop();
            }
            else{
                ans.push_back(q.front());
                break;
            }
        }
        if(q.empty()){
            ans.push_back('#');
        }
    }
    return ans;
}
int main(){
    string exp;
    cout<<"enter string:";
    cin>>exp;
    cout<<firstNonRep(exp)<<endl;
}
