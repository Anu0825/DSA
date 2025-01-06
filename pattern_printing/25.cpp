#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter n:";
    cin>>n;
    for(int i=1;i<=n;i++){
        //print space
        int space=(n-i);
        while(space){
            cout<<" ";
            space--;
            }
        //print 1st triangle
        for(int j=1;j<=i;j++){
            cout<<j;
        }
        //print 2nd triangle
        for(int j=i-1;j>0;j--){
            cout<<j;
        }
        cout<<endl;
}}