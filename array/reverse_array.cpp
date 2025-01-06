#include<iostream>
using namespace std;
void print_array(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    } cout<<endl;
}
void reverse_array(int arr[],int n){
    int start=0,end=n-1;
    while(start<=end){
    swap(arr[start],arr[end]);
    start++;
    end--;
    }
    print_array(arr,n);
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
    reverse_array(arr,n);
}