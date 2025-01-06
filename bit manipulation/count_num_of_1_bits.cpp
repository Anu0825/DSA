#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter n:";
    cin>>n;
    int cnt=0;
    while(n!=0){
        cnt=cnt+(n&1);
        n=n>>1;
    }
    cout<<"count: "<<cnt<<endl;
}