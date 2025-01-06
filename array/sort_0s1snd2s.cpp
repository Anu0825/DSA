// given array has only 0,1 and 2s we have to sort it
#include<iostream>
using namespace std;
void sort1(int arr[],int size){
    int cnt_0=0,cnt_1=0,cnt_2=0;
    for(int i=0;i<size;i++){
        if(arr[i]==0){
            cnt_0++;
        }
        else if(arr[i]==1){
            cnt_1++;
        }
        else{
            cnt_2++;
        }
    }
    for(int i=0;i<cnt_0;i++){
        arr[i]=0;
    }
    for(int i=cnt_0;i<(cnt_0+cnt_1);i++){
        arr[i]=1;
    }
    for(int i=(cnt_0+cnt_1);i<size;i++){
        arr[i]=2;
    }
}
void sort2(int arr[],int size){                  // three pointer approach
    int low=0,mid=0,high=size-1;                 // dutch national algorithm
    while(high>=mid){                            // most optimal approach
        if(arr[mid]==1){                         // time comp. -> O(n)
            mid++;                               // space comp. -> O(1)
        }
        else if(arr[mid]==0){
            swap(arr[mid],arr[low]);
            mid++,low++;
        }
        else{
            swap(arr[mid],arr[high]);
            high--;
        }
    }
}
int main(){
    int size,k;
    cout<<"enter size:";
    cin>>size;
    int *arr=new int[size];
    cout<<"enter array elements:"<<endl;
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    //sort1(arr,size);
    sort2(arr,size);
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}