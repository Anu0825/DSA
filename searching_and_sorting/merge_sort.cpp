#include<iostream>
using namespace std;
void merge(int *arr,int start,int end){
    int mid=(start+end)/2;
    int len1=mid-start+1;
    int len2=end-mid;
    int *first=new int[len1];
    int *second=new int[len2];
    //copy values
    int mainArrayIndex=start;
    for(int i=0;i<len1;i++){
        first[i]=arr[mainArrayIndex++];
    }
    mainArrayIndex=mid+1;
    for(int i=0;i<len2;i++){
        second[i]=arr[mainArrayIndex++];
    }
    // merge 2 sorted array
    int index1=0,index2=0;
    mainArrayIndex=start;
    while(index1<len1 && index2<len2){
        if(first[index1]<second[index2]){
            arr[mainArrayIndex++]=first[index1++];
        }
        else{
            arr[mainArrayIndex++]=second[index2++];
        }
    }
    while(index1<len1){
        arr[mainArrayIndex++]=first[index1++];
    }
    while(index2<len2){
        arr[mainArrayIndex++]=second[index2++];
    }
    delete []first;
    delete []second;
}
void merge_sort(int arr[],int start,int end){
    if (start>=end)
      return;
    int mid=(start+end)/2;
    // left part sort krna hai
    merge_sort(arr,start,mid);
    // right part sort krna hai
    merge_sort(arr,mid+1,end);
    // merge krne ke liye
    merge(arr,start,end);
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
    merge_sort(arr,0,n-1);
    cout<<"sorted array is : ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
