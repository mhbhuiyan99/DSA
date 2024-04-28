Problem Link : https://leetcode.com/problems/house-robber/description/

>>> Top-Down approach

int solve(int i, vector<int> &nums, vector<int> &dp)
{
    if(i == 0) return nums[0];
    if(i < 0) return 0;
    if(dp[i] != -1) return dp[i];

    int take = nums[i] + solve(i-2, nums, dp);
    int not_take = 0 +  solve(i-1, nums, dp);
  
    return dp[i] = max(take, not_take);
}
int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n,-1);
    return solve(n - 1, nums,dp);
}
-----------------------------------------------------

>>> Tabulation approach

int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n,-1);
   
    dp[0] = nums[0];
    for(int i = 1; i < n; i++)
    {
        int take = nums[i] + (i - 2 < 0 ? 0 : dp[i-2]);
        int not_take = 0 + dp[i-1];
        dp[i] = max(take, not_take);
    }
    return dp[n-1];
}
