#include<iostream>
using namespace std;
int main(){
    int n,s=65;
    cout<<"enter n:";
    cin>>n;
    /*for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<char(s)<<" ";
        }
        s++;  */

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<char('A'+i-1)<<" ";
        }
        cout<<endl;
    }
}