#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    cout<<"enter array elements:"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int start=0;
    int end=n-1;
    while(start<=end){
        if(arr[start]<0 && arr[end]<0){
            end--;
        }
        else if(arr[start]<0 && arr[end]>=0){
            swap(arr[start],arr[end]);
            start++;
        }
        else{
            start++;
        }
    }
    cout<<"array elements are:"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
