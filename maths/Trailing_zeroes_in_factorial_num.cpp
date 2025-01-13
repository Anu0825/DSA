/*For an integer n, find the number of trailing zeroes in n!*/
#include<bits/stdc++.h>
using namespace std;
int trailingZeroes(int n) {
        int ans=0;
        while(n>=5){
            int temp=n/5;
            ans+=temp;
            n=n/5;
        }
        return ans;
}
int main(){
    int n;
    cout<<"enter n:";
    cin>>n;
    cout<<trailingZeroes(n)<<endl;
    return 0;
}