// 2 sorted arrays are given. Merge them in array 3 in sorted manner.
#include<iostream>
using namespace std;
void print_array(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    } cout<<endl;
}
void merge(int arr1[],int n1,int arr2[],int n2,int arr[]){
    int i=0,j=0,k=0;
   while(i<n1 && j<n2){
    if (arr1[i]<arr2[j]){
    arr[k]=arr1[i];
    i++; }
    else{
    arr[k]=arr2[j];
    j++; }
    k++;
   }
   //copy krdo 1st array ke remaining elem ko
   while(i<n1){
       arr[k]=arr1[i];
       k++,i++;
   }
   // copy krdo 2nd array ke remaining elem ko
   while(j<n2){
    arr[k]=arr2[j];
    k++,j++;
   }
}
int main(){
    int n1,n2;
    cout<<"enter n1:";
    cin>>n1;
    int arr1[n1];
    cout<<"enter array1 elements:"<<endl;
    for(int i=0;i<n1;i++){
        cin>>arr1[i];
    }
    cout<<"enter n2:";
    cin>>n2;
    int n=n1+n2;
    int arr2[n2];
    cout<<"enter array2 elements:"<<endl;
    for(int i=0;i<n2;i++){
        cin>>arr2[i];
    }
    int arr[n]={0};
    cout<<"merge sortd array is: ";
    merge(arr1,n1,arr2,n2,arr);
    print_array(arr,n);
}