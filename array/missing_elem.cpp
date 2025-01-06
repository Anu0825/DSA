//given an array of 1 to n intg. in which 1 no. is missing we have to find that missing elem
//best approach -> using sum or xor operator
#include<iostream>
using namespace std;
int UsingSum(int arr[],int n){
    int sum=(n*(n+1))/2;               // this approach may overflow in long intg.
    int arrSum=0;                      // xor is much better than sum
    for(int i=0;i<n-1;i++){            // however time comp -> O(n) nd space comp -> O(1) in both
        arrSum+=arr[i];
    }
    return (sum-arrSum);
}
int UsingXor(int arr[],int n){
    int ans=0;
    for(int i=0;i<n-1;i++){                  // we can do it only in 1 loop also
        ans=ans^arr[i];                      // int xor1=0,xor2=0;
    }                                        // for(int i=0;i<n-1;i++){
    for(int i=1;i<=n;i++){                   //       xor1=xor1^arr[i];
        ans=ans^i;                           //       xor2=xor2^(i+1); }
    }                                        //  xor2=xor2^n;
    return ans;                              //  return (xor1^xor2);
}
int main(){
    int n;
    cout<<"enter size:";
    cin>>n;
    int *arr=new int[n];
    cout<<"enter array elements:"<<endl;
    for(int i=0;i<n-1;i++){
        cin>>arr[i];
    }
    cout<<"missing element is: "<<UsingSum(arr,n)<<endl;
    cout<<"missing element is: "<<UsingXor(arr,n)<<endl;

}