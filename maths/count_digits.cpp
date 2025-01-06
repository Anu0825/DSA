#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int n,lastdig;
    int cnt=0;
    cout<<"enter n:";
    cin>>n;
    int dup=n;
    //time comp -> o(log10(n))
    while(n>0){
        lastdig=n%10;
        cnt++;
        n=n/10;
    }
    //second method
    int count=(int)(log10(dup) + 1);
    cout<<"count: "<<cnt<<endl;
    cout<<"count: "<<count<<endl;
}