#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter n:";
    cin>>n;
    /*for(int i=1;i<=n;i++){
        for(int j=i;j>=1;j--){
            cout<<j<<" ";
        }*/
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<(i-j+1)<<" ";
        }
        cout<<endl;
    }
}