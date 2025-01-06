//Given N non-negative integers which signifies the cost of the moving from each stair. Paying the cost at i-th step, you can
// either climb one or two steps. Given that one can start from the 0-the step or 1-the step, the task is to find the minimum 
//cost to reach the top of the floor(N+1) by climbing N stairs.
#include <bits/stdc++.h>
using namespace std;
// using recursion
int minimumCost1( int n , int cost[]){
	if(n == 0) 
       return cost[0] ;
	if(n == 1) 
       return cost[1] ;
	int top = min( minimumCost1(n-1,cost),minimumCost1(n-2, cost))+ cost[n];
	return top;
}
//using memoization
int minimumCost2( int n , vector<int> &cost,vector<int> &dp){
	if(n == 0) 
       return cost[0] ;
	if(n == 1) 
       return cost[1] ;
	int top = min( minimumCost2(n-1,cost,dp),minimumCost2(n-2, cost,dp))+ cost[n];
	return top;
}
int minCostClimbingStairs(vector<int> &cost)
{
    int n = cost.size();
    vector<int> dp(n + 1, -1);
    int ans = min(minimumCost2(n - 2, cost, dp),minimumCost2(n - 1, cost, dp));
    return ans;
}
// using tabulation
int minimumCost3(int cost[], int n)
{
    // declare an array
    int dp[n];
 
    // base case
    if (n == 1)
        return cost[0];
    dp[0] = cost[0];
    dp[1] = cost[1];
 
    // iterate for finding the cost
    for (int i = 2; i < n; i++) {
        dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
    }
 
    // return the minimum
    return min(dp[n - 2],dp[n-1]);
}
// using space optimisation
int minimumCost4(int cost[], int n)
{
    int dp1 = 0, dp2 = 0;
 
    // traverse till N-th stair
    for (int i = 0; i < n; i++) {
        int dp0 = cost[i] + min(dp1, dp2);
        // update the last two stairs value
        dp2 = dp1;
        dp1 = dp0;
    }
    // dp2 gives the cost if started climbing from index 1
    // and dp1 from index 0
    return min(dp2, dp1);
}
int main()
{
	int a[] = { 16, 19, 10, 12, 18 };
	int n = sizeof(a) / sizeof(a[0]);

	cout << minimumCost1(n-2, a)<<endl;
    vector<int> cost{ 10, 15, 20 };
    cout << minCostClimbingStairs(cost)<<endl;
    cout<<minimumCost3(a,n)<<endl;
    cout<<minimumCost4(a,n)<<endl;
	return 0;
}
