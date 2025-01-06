#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter size:";
    cin>>n;
    int arr[n];
    cout<<"enter array elements:";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int xor_;
    cout<<"enter xor";
    cin>>xor_;
    for(int i=0;i<n;i++){
        int resxor=1;
        for(int j=i+1;j<n;j++){
            resxor=resxor^arr[j];
        }
    }
}