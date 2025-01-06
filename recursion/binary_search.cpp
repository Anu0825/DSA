#include<iostream>
using namespace std;
bool binary_search(int arr[],int n,int start,int end,int key){
if (start>end)
    return false;
int mid=start+(end-start)/2;
if (arr[mid]==key)
    return true;
if (arr[mid]<key)
    return binary_search(arr,n,mid+1,end,key);
else
    return binary_search(arr,n,start,mid-1,key);
}
int main(){
int n;
cin>>n;
int key;
cout<<"enter key:"<<endl;
cin>>key;
int arr[n];
cout<<"enter array elements:"<<endl;
for(int i=0;i<n;i++){
    cin>>arr[i];
}
cout<<"present or not:"<<binary_search(arr,n,0,(n-1),key)<<endl;
}