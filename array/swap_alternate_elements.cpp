#include<iostream>
using namespace std;
void print_array(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    } cout<<endl;
}
void swap_array(int arr[],int n){
    int start=0;
    while((start+1)<n){
    swap(arr[start],arr[start+1]);
    start=start+2;
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
    swap_array(arr,n);
}