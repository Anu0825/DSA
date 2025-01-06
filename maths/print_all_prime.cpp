// sieve of eratosthenes algorithm
#include<iostream>
using namespace std;
int main(){
    int num;
    cout<<"enter num:";
    cin>>num;
    int arr[num+1];
    for(int i=2;i<=num;i++){
        arr[i]=1;
    }
    /*for(int i=2;i<=num;i++){
        if(arr[i]==1){
            for(int j=2*i;j<=num;j=j+i){
                arr[j]=0;
            }
        }
    }*/
   // more optimised solution time comp -> O(n log log n)
    for(int i=2;i*i<=num;i++){
        if(arr[i]==1){
            for(int j=i*i;j<=num;j=j+i){
                arr[j]=0;
            }
        }
    }
    for(int i=2;i<=num;i++){
        if(arr[i]==1){
            cout<<i<<" ";
        }
    }
}