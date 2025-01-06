#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter size:";
    cin>>n;
    int arr[n][n];
    cout<<"enter array elements:"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    /*for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j){
            swap(arr[i][j],arr[i][n-j-1]);
        }
    }
    }*/
     for(int i=0;i<n;i++){
            swap(arr[i][i],arr[i][n-i-1]);
        }
    cout<<"reverse diagonal matrix is:"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}