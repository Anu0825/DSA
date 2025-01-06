#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter n:";
    cin>>n;
    int arr[n];
    cout<<"enter array elements:"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int sum=0;       
    for(int i=0;i<n;i++){
        sum=sum+arr[i];
    }
    cout<<"the sum is: "<<sum<<endl;
}