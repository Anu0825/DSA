#include<iostream>
using namespace std;
int main(){
    int n,ans=0;
    cout<<"enter n:";
    cin>>n;
    int dup=n;
    while(n>0){
        int lastdig=n%10;
        n=n/10;
        ans=(ans*10)+lastdig;
    }
    if(dup==ans){
        cout<<"its palindrome"<<endl;
    }
    else{
        cout<<"not a palindrome"<<endl;
    }
}