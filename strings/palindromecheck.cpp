#include<iostream>
using namespace std;
char ToLowerCase(char ch){
    if(ch>='a' && ch<='z'){
        return ch;
    }
    else{
        char temp=ch-'A'+'a';
        return temp;
    }
}
char ToUpperCase(char ch){
    if(ch>='A' && ch<='Z'){
        return ch;
    }
    else{
        char temp=ch-'a'+'A';
        return temp;
    }
}
bool palindrome(string str){
    int start=0,end=str.size()-1;
    while(start<=end){
        /*if(!(str[start]>='a' && str[start]<='z') || !(str[start]>=0)){
            start++;
        }*/
        if(!isalnum(str[start])){
            start++;
        }
        else if(!isalnum(str[end])){
            end--;
        }
        /*else if(!(str[end]>='a' && str[end]<='z') || !(str[end]>=0)){
            end--;
        }*/
        else if(ToLowerCase(str[start])!=ToLowerCase(str[end])){
            return false;
        }
        else{
          start++,end--; 
        }
    }
    return true;
}
int main(){
    string str="0P";
    cout<<palindrome(str)<<endl;
    cout<<ToLowerCase('A')<<endl;
}
