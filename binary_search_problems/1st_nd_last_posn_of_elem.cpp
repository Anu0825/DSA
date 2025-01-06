//find the first and last position of an elem in a sorted array using binary search
//ex: {0,1,2,2,2,2,3,4} --> 1st of 2 at 2 and last at 5
// time complexity O(logn)
#include<iostream>
using namespace std;
int first_occ(int arr[],int n,int key){
    int start=0,end=n-1,ans=-1;
    int mid=(start+end)/2;
    while(start<=end){
        if(arr[mid]==key){
            ans=mid;
            end=mid-1;
        }
        if(arr[mid]>key){
            end=mid-1;
        }
        if(arr[mid]<key){
            start=mid+1;
        }
        mid=(start+end)/2;
    }
    return ans;
}
int last_occ(int arr[],int n,int key){
    int start=0,end=n-1,ans=-1;
    int mid=(start+end)/2;
    while(start<=end){
        if(arr[mid]==key){
            ans=mid;
            start=mid+1;
        }
        if(arr[mid]>key){
            end=mid-1;
        }
        if(arr[mid]<key){
            start=mid+1;
        }
        mid=(start+end)/2;
    }
    return ans;
}
int main(){
    int n,key;
    cout<<"enter n:";
    cin>>n;
    cout<<"enter key:";
    cin>>key;
    int arr[n];
    cout<<"enter array elements:"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"first occurance is at index "<<first_occ(arr,n,key)<<endl;
    cout<<"last occurance is at index "<<last_occ(arr,n,key)<<endl;
    if((first_occ(arr,n,key)!=-1) && (last_occ(arr,n,key)!=-1))
    cout<<"Total no. of occurances are "<<(last_occ(arr,n,key)-first_occ(arr,n,key))+1<<endl;
}