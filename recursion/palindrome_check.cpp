#include<iostream>
using namespace std;
bool rev_str(string& str,int i,int j){
    if (i>j)
        return true;
    if (str[i]!=str[j])
        return false;
    else
        return rev_str(str,i+1,j-1);
}
int main(){
cout<<"enter string:"<<endl;
string str;
cin>>str;
if(rev_str(str,0,str.length()-1)){
           cout<<"Its a palindrome."<<endl;
}
else{
    cout<<"Its not a palindrome"<<endl;
}
}