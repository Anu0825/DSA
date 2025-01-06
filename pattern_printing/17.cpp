#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter n:";
    cin>>n;
    for(int i=1;i<=n;i++){
        int value=65+n-i;
        for(int j=1;j<=i;j++){
            cout<<char(value)<<" ";
            value++;
        }
        cout<<endl;
    }

}