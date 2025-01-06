#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter n:";
    cin>>n;
    for(int i=1;i<=n;i++){
        int a=i;
        for(int j=1;j<=i;j++){
            cout<<a<<" ";
            a++;
        }
        //without another variable
        /*for(int j=i;j<(2*i);j++){
            cout<<j<<" ";
        }*/
       //or
       /*for(int j=1;j<=i;j++){
           cout<<(i+j-1)<<" ";
       }*/
        cout<<endl;
    }
}