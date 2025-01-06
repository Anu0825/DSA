//without using multiplication and division operator
#include<iostream>
using namespace std;
int main(){
    int dividend,divisor;
    cout<<"enter dividend and divisor:";
    cin>>dividend>>divisor;
    int cnt=0,ans=0;
    while(ans+divisor<=dividend){
        ans=ans+divisor;
        cnt++;
    }
    cout<<cnt<<endl;
}