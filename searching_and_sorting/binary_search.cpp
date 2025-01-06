// time complexity O(log n)
#include<iostream>
using namespace std;
int binary_search(int arr[],int n,int key){
    int start=0,end=n-1;
    int mid=(start+end)/2;         //when we perform this op on very large intg. this may give error
    while(start<=end){             //there we can use mid=start+((end-start)/2);
    if (key==arr[mid]){
        return mid;
    }
    // go to right part
    if(key>arr[mid]){
        mid=(mid+1+end)/2;
    }
    // go to left part
    if(key<arr[mid]){
        mid=(start+(mid-1))/2;
    }}
    return -1;
}
int main(){
    int n,key;
    cout<<"enter n:";
    cin>>n;
    cout<<"enter key:";
    cin>>key;
    int arr[n];
    cout<<"enter array elements:"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans=binary_search(arr,n,key);
    if(ans!=-1){
        cout<<"element found at index "<<ans<<endl;
    }
    else{
        cout<<"element is not present"<<endl;
    }

}