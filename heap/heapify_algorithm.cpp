// heapify algorithm -> convert array into max nd min heap
#include<iostream>
using namespace std;
void heapify_maxHeap(int arr[],int n,int i){
    int largest=i;
    int left=2*i;
    int right=2*i +1;
    if(left < n && arr[largest]< arr[left]){
        largest=left;
    }
    if(right < n && arr[largest]<arr[right]){
        largest=right;
    }
    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapify_maxHeap(arr,n,largest);
    }
}
void heapify_minHeap(int arr[],int n,int i){
    int smallest=i;
    int left=2*i ;
    int right=2*i + 1;
    if(left < n && arr[smallest]> arr[left]){
        smallest=left;
    }
    if(right < n && arr[smallest]>arr[right]){
        smallest=right;
    }
    if(smallest!=i){
        swap(arr[smallest],arr[i]);
        heapify_minHeap(arr,n,smallest);
    }
}
int main(){
    int arr[6]={-1,54,53,55,52,50};
    int n=5;
    for(int i=n/2;i>0;i--){
        heapify_maxHeap(arr,n,i);
    }
    cout<<"printing the array for max heap:"<<endl;
    for(int i=1;i<=5;i++){
            cout<<arr[i]<<" ";
        }cout<<endl;
    int arr1[6]={-1,54,53,55,52,50};
    for(int i=n/2;i>0;i--){
        heapify_minHeap(arr1,n,i);
    }
    cout<<"printing the array for min heap:"<<endl;
    for(int i=1;i<=5;i++){
            cout<<arr1[i]<<" ";
        }cout<<endl;
}
