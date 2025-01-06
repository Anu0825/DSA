//pivot --> index at which minimum elem is present
//given array is sorted half in inc and half in dec.--> rotated sorted array
#include<iostream>
using namespace std;
int pivot_elem(int arr[],int n){
    int start=0,end=n-1;
    int mid=(start+end)/2;
    while(start<end){
        if(arr[mid]<arr[0])
           end=mid;
        else
           start=mid+1;
        mid=(start+end)/2;
    }
    return start;
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
    cout<<"pivot is: "<<pivot_elem(arr,n)<<endl;
}