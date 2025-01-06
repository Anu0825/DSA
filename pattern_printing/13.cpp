#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter n:";
    cin>>n;
    /*for(int i=0;i<n;i++){
        int s=65+i;
        for(int j=1;j<=n;j++){
            cout<<char(s)<<" ";
            s++;
        }  
        cout<<endl;
    }*/
   for(int i=1;i<=n;i++){
    for(int j=0;j<=n;j++){
        cout<<char('A'+i+j-2)<<" ";
    }
    cout<<endl;
   }
}