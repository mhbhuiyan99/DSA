Problem Link : [Frog Jump](https://bit.ly/3JPcoOx)

int solve(int n, vector<int> &heights, vector<int> &dp)
{
    if(n == 0) return 0;
    if(dp[n] != -1) return dp[n];

    int oneMove = solve(n - 1, heights, dp) + abs(heights[n] - heights[n-1]);
    int twoMove = INT_MAX;
    if(n > 1) 
        twoMove = solve(n-2, heights, dp) + abs(heights[n] - heights[n-2]);

    return dp[n] = min(oneMove, twoMove);
}

int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n+1, -1);
    return solve(n-1, heights, dp);
}
