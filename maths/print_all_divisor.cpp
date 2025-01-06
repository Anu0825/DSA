#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int n;
    cout<<"enter number:";
    cin>>n;
    // time comp. -> O(n)
    /*for(int i=1;i<=n;i++){
        if(n%i==0){
            cout<<i<<" ";
        }
    }*/  
   // time comp O(sqrt(n))
   for(int i=1;i<=sqrt(n) /*or (i*i<=n)*/;i++){
    if(n%i==0){
        cout<<i<<" ";
        if(n/i!=i){
          cout<<n/i<<" ";}
    }
   }
}