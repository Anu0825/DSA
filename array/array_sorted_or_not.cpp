#include<iostream>
using namespace std;
bool array_sorted(int arr[],int n){
    for(int i=1;i<n;i++){
        if(arr[i-1]<=arr[i])
           continue;
        else
           return false;
    }
    return true;
}
int main(){
    int n;
    cout<<"enter n:";
    cin>>n;
    int arr[n];
    cout<<"enter array elements:"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    if(array_sorted(arr,n)){
        cout<<"array is sorted"<<endl;
    }
    else{
        cout<<"array is not sorted"<<endl;
    }
}