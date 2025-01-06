// find the maximum no. of consecutive ones in an array
// eg. {1,1,0,0,1,1,1,0,1,1} -> ans=3
#include<iostream>
using namespace std;
int MaxConsecutiveOnes(int arr[],int n){
    int cnt=0,max1=0;
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            cnt=0;
        }
        else{
            cnt++;
            max1=max(cnt,max1);
        }
    }
    return max1;
}
int main(){
    int n;
    cout<<"enter n:";
    cin>>n;
    int *arr=new int[n];
    cout<<"enter array elements:"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"max consecutive ones are: "<<MaxConsecutiveOnes(arr,n)<<endl;
}