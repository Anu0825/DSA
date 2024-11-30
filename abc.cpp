#include<iostream>
#include<vector>
using namespace std;
int binary_search(int n,int arr[],int s,int e){
     int mid=(s+e)/2;
     if(mid<=e){
         if(arr[mid]>0){
             return binary_search(n,arr,mid+1,e);
         }
         else if(arr[mid]<0 && mid!=0 && arr[mid-1]>0){
             return mid;
         }
         else if(arr[mid]<0 && mid==0){
             return mid;
         }
         else{
             return binary_search(n,arr,s,mid-1);
         }
     }
     return -1;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int idx=binary_search(n,arr,0,n-1);
    cout<<idx<<endl;
}