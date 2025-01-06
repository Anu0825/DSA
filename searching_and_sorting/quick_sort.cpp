#include<iostream>
using namespace std;
int partition(int arr[],int s,int e){
    int pivot=arr[s];
    int count=0;
    for(int i=s+1;i<=e;i++){
        if(arr[i]<=pivot)
             count++;
    }
    // place pivot at its right position
    int pivotIndex=s+count;
    swap(arr[pivotIndex],arr[s]);
    //left and right vala part
    int i=s,j=e;
    while(i<pivotIndex && j>pivotIndex){
        while(arr[i]<=pivot){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        if(i<pivotIndex && j>pivotIndex){
            swap(arr[i++],arr[j--]);
        }
    }
    return pivotIndex;
}
void quick_sort(int arr[],int s,int e){
    if(s>=e)
        return;
    //partition ke liye
    int p=partition(arr,s,e);
    //left part sort ke liye
    quick_sort(arr,s,p-1);
    //right part sort ke liye
    quick_sort(arr,p+1,e);
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
    quick_sort(arr,0,n-1);
    cout<<"sorted array is : ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}