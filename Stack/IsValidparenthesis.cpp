//important ques
// check given exp is balanced or not
// eg. {()} -> VALID , {[}] -> NOT VALID
#include<iostream>
#include<stack>
using namespace std;
bool IsValidParenthesis(string expression){
    stack<char> st;
    for(int i=0;i<expression.length();i++){
        char ch=expression[i];
        //if opening bracket
        if(ch=='{' || ch=='(' || ch=='['){
            st.push(ch);
        }
        else{
            //if closing bracket
            if(!st.empty()){
                char top=st.top();
                if((ch=='}' && top=='{') || (ch==')'&& top=='(') || (ch==']'&&top=='[')){
                    st.pop();
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }

    }
    if(st.empty()){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    string expression;
    cout<<"enter string:";
    cin>>expression;
    if(IsValidParenthesis(expression)){
        cout<<"balanced expression"<<endl;
    }
    else{
        cout<<"unbalanced expression"<<endl;
    }
}