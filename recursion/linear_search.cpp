#include<iostream>
using namespace std;
bool linear_search(int arr[],int n,int key){
if (n==0)
    return false;
if (arr[0]==key)
    return true;
else
    return linear_search(arr+1,n-1,key);
}
int main(){
int n;
cin>>n;
int key;
cout<<"enter key:"<<endl;
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
    cout<<"key not found"<<endl;
}
}