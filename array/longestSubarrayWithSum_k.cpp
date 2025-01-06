// you have to find the length of the longest subarray(contigous part of array) with sum k.
// all array elements are positive
// eg. {1,2,3,1,1,1,1,4,2,3} nd k=3 -> ans= {1,1,1}
#include<iostream>
#include<vector>
using namespace std;
int longSubarray(int arr[],int size,int k){
    int len=0;
    for(int i=0;i<size;i++){                     // time comp O(n^3) 
        for(int j=i;j<size;j++){
            int sum=0;
            for(int k=i;k<=j;k++){
                sum=sum+arr[k];
            }
            if(sum==k){
                    len=max(len,j-i+1);
                }
        }}
        return len;
}
int longSubarray1(int arr[],int size,int k){
    int len=0;
    for(int i=0;i<size;i++){   
        int sum=0;                  // time comp O(n^2) 
        for(int j=i;j<size;j++){
            sum=sum+arr[j];
            if(sum==k){
                    len=max(len,j-i+1);
                }
        }}
        return len;
}

int main(){
    int size,k;
    cout<<"enter size:";
    cin>>size;
    cout<<"enter k:";
    cin>>k;
    int *arr=new int[size];
    cout<<"enter array elements:"<<endl;
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    cout<<"the length of longest subarray is: "<<longSubarray1(arr,size,k)<<endl;
}