//reverse the array after specific index 
#include<iostream>
using namespace std;
void print_array(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    } cout<<endl;
}
void reverse_array(int arr[],int n,int index){
    int start=index+1,end=n-1;
    while(start<=end){
    swap(arr[start],arr[end]);
    start++;
    end--;
    }
    print_array(arr,n);
}
int main(){
    int n,index;
    cout<<"enter n:";
    cin>>n;
    cout<<"enter index:";
    cin>>index;
    int arr[n];
    cout<<"enter array elements:"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    reverse_array(arr,n,index);
}