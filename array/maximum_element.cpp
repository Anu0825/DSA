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
    int max=arr[0];       // max=INT_MIN --> -2^31
    for(int i=0;i<n;i++){
        if (arr[i]>max){    // at place of if block we can use max_=max(max_,arr[i])
            max=arr[i];
        }
    }
    cout<<"the maximum element is: "<<max<<endl;
}