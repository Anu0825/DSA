#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter n:";
    cin>>n;
    int arr1[n];
    cout<<"enter array1 elements:"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr1[i];
    }
    int min=arr1[0];    
    for(int i=0;i<n;i++){
        if (arr1[i]<min){  
            min=arr1[i];
        }
    }
    int secmin=arr1[0];
    for(int i=0;i<n;i++){
        if(arr1[i]<secmin && arr1[i]!=min)
            secmin=arr1[i];
    }
    cout<<"the 2nd smaller element is: "<<secmin<<endl;
}