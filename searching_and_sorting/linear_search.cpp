// time complexity O(n)
#include<iostream>
using namespace std;
int linear_search(int arr[],int n,int key){
    for(int i=0;i<n;i++){
        if (key==arr[i]){
            return 1;
        }}
        return 0;
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
    if(linear_search(arr,n,key)){
        cout<<"key found"<<endl;
    }
    else{
        cout<<"key is not present."<<endl;
    }
}