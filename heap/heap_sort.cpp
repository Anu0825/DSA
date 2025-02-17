#include<iostream>
using namespace std;
void heapify(int arr[],int n,int i){
    int largest=i;
    int left=2*i;
    int right=2*i +1;
    if(left <= n && arr[largest]< arr[left]){
        largest=left;
    }
    if(right <= n && arr[largest]<arr[right]){
        largest=right;
    }
    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}
void heapsort(int arr[],int n){
    int size=n;
    while(size > 1){
        //step 1 -> swap
        swap(arr[size],arr[1]);
        size--;
        // step 2
        heapify(arr,size,1);
    }
}
int main(){
    int arr[6]={-1,54,53,55,52,50};
    int n=5;
    // heap creation
    for(int i=n/2;i>0;i--){
        heapify(arr,n,i);
    }
    // heap sort
    heapsort(arr,n);
    cout<<"printing the sorted array:"<<endl;
    for(int i=1;i<=5;i++){
            cout<<arr[i]<<" ";
        }cout<<endl;
}