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
    int max=arr[0];  
    for(int i=0;i<n;i++){
        if (arr[i]>max){    
            max=arr[i];
        }
    }
    int sec_max=-1;
    for(int i=0;i<n;i++){
        if(arr[i]>sec_max && arr[i]!=max)
           sec_max=arr[i];
    }
    cout<<"the 2nd maximum element is: "<<sec_max<<endl;
}