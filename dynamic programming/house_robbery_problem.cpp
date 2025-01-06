//There are N houses built in a circle, each of which contains some value in it. A thief is going to steal the maximum value 
// of these houses, but he can’t steal in two adjacent houses because the owner of the stolen houses will tell his two 
//neighbors left and right sides. The task is to find what is the maximum stolen value.
// here first and last houses are neighbours so we cant take both at sme tym as they are present in a circular form.
#include<iostream>
#include<vector>
using namespace std;
// recursion
int solve(vector<int> &nums,int n){
    //base case 
    if(n<0)
       return n;
    if(n==0)
       return nums[0];
    int incl=solve(nums,n-2)+nums[n];
    int excl=solve(nums,n-1)+0;
    return max(incl,excl);
}
// memoization
int solve2(vector<int> &nums,int n,vector<int> &dp){
    //base case 
    if(n<0)
       return n;
    if(n==0)
       return nums[0];
    if(dp[n]!=-1)
       return dp[n];
    int incl=solve(nums,n-2)+nums[n];
    int excl=solve(nums,n-1)+0;
    dp[n]=max(incl,excl);
    return dp[n];
}
int maxValue(vector<int> &nums){
    int n=nums.size();
    vector<int> dp(n,-1);
    return solve2(nums,n-1,dp);
}
// tabulation
int solve3(vector<int> &nums){
    int n=nums.size();
    vector<int> dp(n,-1);
    dp[0]=nums[0];
    for(int i=1;i<n;i++){
        int incl=dp[i-2]+nums[i];
        int excl=dp[i-1]+0;
        dp[i]=max(incl,excl);
    }
    return dp[n-1];
}
// spc optimisation
int solve4(vector<int> &nums){
    int n=nums.size();
    int prev2=0;
    int prev1=nums[0];
    for(int i=1;i<n;i++){
        int incl=prev2+nums[i];
        int excl=prev1+0;
        int ans=max(incl,excl);
        prev2=prev1;
        prev1=ans;
    }
    return prev1;
}
int main(){
    int n;
    cout<<"enter n:";
    cin>>n;
    vector<int> nums;
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout<<solve(nums,n)<<endl;
    cout<<maxValue(nums)<<endl;
    cout<<solve3(nums)<<endl;
    cout<<solve4(nums)<<endl;
}