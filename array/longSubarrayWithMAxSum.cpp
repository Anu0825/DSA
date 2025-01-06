// find the longest subarray whose sum is maximum
// eg. {-2,-3,4,-1,-2,1,5,-3} -> maxsum= 7 {4,-1,-2,1,5}
#include<iostream>
using namespace std;
int maxSum(int arr[],int size){
    int maxi=INT8_MIN;                            //kadane's algo(most optimal approach)
    int sum=0;                                    // time comp O(n)
    for(int i=0;i<size;i++){                      // space comp O(1)
        sum=sum+arr[i];
        if(sum<0){
            sum=0;
        }
        maxi=max(maxi,sum);
    }
    return maxi;
}
int maxSum1(int arr[],int size){
    int maxi=0;
    for(int i=0;i<size;i++){   
        int sum=0;                  // time comp O(n^2) 
        for(int j=i;j<size;j++){
            sum=sum+arr[j];
            maxi=max(maxi,sum);
        }}
        return maxi;
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
    cout<<"the maximum sum of longest subarray is: "<<maxSum1(arr,size)<<endl;
    cout<<"the maximum sum of longest subarray is: "<<maxSum(arr,size)<<endl;
}