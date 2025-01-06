//move all zero elem in the end of array
// eg. {1,0,2,3,0,0} --> {1,2,3,0,0,0}
#include<iostream>
using namespace std;
void move_zero(int arr[],int n){
    int j=0;
    for(int i=0;i<n;i++){
        if (arr[i]!=0){
            swap(arr[i],arr[j]);
            j++;
        }
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
    move_zero(arr,n);
    cout<<"resultant array is"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}