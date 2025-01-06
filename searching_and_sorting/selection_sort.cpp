// time complexity O(n^2)
#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter n:";
    cin>>n;
    int arr[n];
    cout<<"enter array elements:"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=(i+1);j<n;j++){
              if (arr[min]>arr[j]){
                min=j;
              }
        }
        swap(arr[min],arr[i]);
    }
    cout<<"sorted elements are: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}