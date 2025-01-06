#include<iostream>
using namespace std;
int main(){
    int n,ans=0;
    cout<<"enter n:";
    cin>>n;
    while(n>0){
        int lastdig=n%10;
        n=n/10;
        ans=(ans*10)+lastdig;
    }
    cout<<ans<<endl;
}