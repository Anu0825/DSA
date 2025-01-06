//given array is in the form of mountain first sorted inc. and then dec. we have to find peak element
// ex={2,3,4,5,4,3,2} --> 5
// first method using for loop and find the maximum element
#include<iostream>
using namespace std;
int peak_elem(int arr[],int n){
    int start=0,end=n-1,ans;
    int mid=(start+end)/2;
    while(start<end){
    if(arr[mid]>arr[mid+1])
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
    cout<<"the peak element is "<<arr[peak_elem(arr,n)]<<endl;
}