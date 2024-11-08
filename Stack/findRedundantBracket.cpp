// if redundant brackets are present return true else false
//in input expression operator,lower eng. alphabet and brackets are presnt.
// redundant brackets that are of no use eg. ((a+b)) -> outside brackets are redundant
//(a+(b*c)) -> no redundant brackets
#include<iostream>
#include<stack>
using namespace std;
bool findRedundantBracket(string expression){
    stack<char> st;
    for(int i=0;i<expression.length();i++){
        char ch=expression[i];
        if(ch=='('||ch=='+'||ch=='-'||ch=='*'||ch=='/'){
            st.push(ch);
        }
        else{
            if(ch==')'){
                bool isRedundant=true;
                while(st.top()!='('){
                     char top=st.top();
                     if(top=='+' || top=='-' || top=='*' || top=='/'){
                          isRedundant=false;
                      }
                      st.pop();
                }
                if(isRedundant==true){
                    return true;
                }
                st.pop();
            }
        }
    }
    return false;
}
int main(){
     string expression;
     cout<<"enter string:";
     cin>>expression;
     if(findRedundantBracket(expression)){
        cout<<"redundant brackets are present"<<endl;
     }
     else{
        cout<<"redundant brackets are not present"<<endl;
     }
}