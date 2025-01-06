// other approach is to convert the no. into binary and check the no. of set bits if 1 then power of 2.
#include<iostream>
using namespace std;
int power(int a,int b=2){
      if(a==0){
        return 1;
      }
      return b*power(a-1,b);
}
bool check_power(int n){
    for(int i=1;i<n/2;i++){
        int res=power(i);
        if(res==n){
            return true;
        }
    }
    return false;
}
// best solution
bool isPowerOfTwo(int n){
    if(n<=0) {
      return false;}
    return ((n&(n-1))==0);
}
int main(){
    int n;
    cout<<"enter n:";
    cin>>n;
    cout<<check_power(n)<<endl;
    cout<<isPowerOfTwo(n)<<endl;
}
