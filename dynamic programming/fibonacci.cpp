#include<iostream>
#include<vector>
using namespace std;
// recursion
int fibo1(int n){
    if(n==0 || n==1){
        return n;
    }
    return fibo1(n-1)+fibo1(n-2);
}
// recursion + memoization
int fibo2(int n,vector<int> &dp){
    //base case
    if(n==0 || n==1){
        return n;
    }
    //step 3
    if(dp[n]!=-1){
        return dp[n];
    }
    //step 2
    dp[n]=fibo2(n-1,dp)+fibo2(n-2,dp);
    return dp[n];
}
// Tabulation 
int fibo3(int n,vector<int> &dp){
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}
// space optimisation
int fibo4(int n){
    int prev1=1;
    int prev2=0;
    int curr;
    for(int i=2;i<=n;i++){
        curr=prev1+prev2;
        prev2=prev1;
        prev1=curr;
    }
    return prev1;
}
int main(){
    int n;
    cout<<"enter n:";
    cin>>n;
    cout<<fibo1(n)<<endl;
    vector<int> dp(n+1);
    for(int i=0;i<n+1;i++){
        dp[i]=-1;
    }
    cout<<fibo2(n,dp)<<endl;
    cout<<fibo3(n,dp)<<endl;
    cout<<fibo4(n)<<endl;
    return 0;
}