#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter n:";
    cin>>n;
    for(int i=1;i<=n;i++){
        int space=(n-i);
        for(int j=1;j<=space;j++){
            cout<<" ";
        }
        for(int s=(space+1);s<=n;s++){
            cout<<"*";
        }
        cout<<endl;
    }
}