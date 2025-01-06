#include<iostream>
using namespace std;
//best approach by observing pattern
// time comp O(1) nd space comp O(1)
int find_xor(int n){
   if(n%4==1)
      return 1;
   else if(n%4==2)
      return n+1;
   else if(n%4==3)
      return 0;
   else
      return n;
}
int main(){
    int n,ans=0,left,right;
    cout<<"enter n:";
    cin>>n;
    cout<<"enter range:";
    cin>>left>>right;
    //time comp O(n)
    for(int i=1;i<=n;i++){
        ans=ans^i;
    }
    cout<<"xor of all numbers till n: "<<find_xor(n)<<endl;
    cout<<"xor of all numbers in given range: "<<(find_xor(left-1)^find_xor(right))<<endl;
}