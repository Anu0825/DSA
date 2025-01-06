//search element in a rotated sorted array
// ex={1,2,3,7,9} --> after rotation --> {7,9,1,2,3} now find specific elem
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
int binary_search(int arr[],int key,int start,int end){
    int mid=(start+end)/2;         
    while(start<=end){
    if (key==arr[mid]){
        return mid;
    }
    if(key>arr[mid]){
        mid=(mid+1+end)/2;
    }
    if(key<arr[mid]){
        mid=(start+(mid-1))/2;
    }}
    return -1;
}
int main(){
    int n,ans,key;
    cout<<"enter n:";
    cin>>n;
    cout<<"enter key:";
    cin>>key;
    int arr[n];
    cout<<"enter array elements:"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int pivot=pivot_elem(arr,n);
    if (arr[pivot]<=key && key<=arr[n-1]){
        ans=binary_search(arr,key,pivot,n-1);
    }
    else{
        ans=binary_search(arr,key,0,pivot-1);
    }
    cout<<"the elem is present at index "<<ans<<endl;
}
