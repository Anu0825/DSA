#include<iostream>
using namespace std;
void insertion_sort(int arr[], int n){
    for(int i=0;i<n;i++){
       int temp=arr[i];
       int j=i-1;
       for(;j>=0;j--){
          if(arr[j]>temp){
            // shift
            arr[j+1]=arr[j];
          }
          else{
            break;
          }
       }
       // copy temp value
       arr[j+1]=temp;
    }
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
    insertion_sort(arr,n);
    cout<<"sorted array is : ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}